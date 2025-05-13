// Virtual area master.                         Written by Sauron, 220897.

#include "/players/sauron/include/virtual.h"
#include "/players/sauron/include/virtualFunctions.c"

#define PARSE_LIMIT             60

private string sMaster;         // The file_name of this master object.

private int iMaxX;              // Maximum x dimension (width of the area).
private int iMaxY;              // Maximum y dimension (depth of the area).
private int iMaxZ;              // Maximum z dimension (height of the area).

private mapping mBorderRooms;   // Connections to the outside world.
private mapping mVirtualRooms;  // Connections within the area.
private mapping mMaps;          // Store the maps for each level of the area.
private mapping mMapKeys;       // Store the keys for the maps.

// Prototyping:

nomask void initBorderRoom(int *iaCoords);
nomask void initVirtualRoom(int *iaCoords);
nomask int validRoom(int *iaCoords);
nomask int *validExits(int *iaCoords);
nomask object cloneRoom(int *iaCoords);
private void setupBorderExits(int *iaCoords);
private void setupVirtualExit(int *iaCoordsA, int iAToB);
nomask void initialiseExits(int *iaCoords);
nomask static void parseMap2(string *saArr, int iZ, int iY);    
private void parseMap(int iZ);
void setAreaSize(int iX, int iY, int iZ);
void setMapKey(string sKey, string sFile);
void setMap(int iZ, string sMap);
void setBorderRoom(int *iaCoords, string sDirToBorder, string sFile);
void notify_destruct(object oOb);
void reset(int iArg);
void init();

// End prototyping.

// Initialise the border rooms mapping.
// Key   = encoded co-ords of the room.
// Value = a mapping of exit information:
//         Key   = direction string.
//         Value = file_name of adjacent hard coded room.

nomask void initBorderRoom(int *iaCoords) {
    string sTmp;
    int    i;

    if(!mBorderRooms)
        mBorderRooms = ([]);
    sTmp = encodeCoords(iaCoords);
    if(!mBorderRooms[sTmp]) {
        mBorderRooms[sTmp] = allocate(B_SIZE);
        for(i = 0; i < B_SIZE; i++)
            mBorderRooms[sTmp][i] = ({});
        mBorderRooms[sTmp] = ([]);
    }
}

// Initialise the virtual rooms mapping.
// Key   = encoded co-ords of the room.
// Value = an array consisting of 3 pieces of information:
//         1: the cloned room object for this location (once cloned).
//         2: a mapping of exits to other adjacent virtual rooms.
//            Key   = direction string.
//            Value = object pointer for adjacent room.
//         3: The single letter key used to identify this room on the map.

nomask void initVirtualRoom(int *iaCoords) {
    string sTmp;

    if(!mVirtualRooms)
        mVirtualRooms = ([]);
    sTmp = encodeCoords(iaCoords);
    if(!mVirtualRooms[sTmp]) {
#ifdef DEBUG
        tell_room(this_object(),
                  "Initialising virtual room at '"+sTmp+"'.\n");
#endif // DEBUG
        mVirtualRooms[sTmp] = allocate(V_SIZE);
        mVirtualRooms[sTmp][EXITS] = ([]);
    }
}

// Are the given room co-ordinates valid? Returns 1 for yes, 0 for no.

nomask int validRoom(int *iaCoords) {
    if(iaCoords[0] < 0 || iaCoords[0] > iMaxX-1)
        return 0;
    else if(iaCoords[1] < 0 || iaCoords[1] > iMaxY-1)
        return 0;
    else if(iaCoords[2] < 0 || iaCoords[2] > iMaxZ-1)
        return 0;
    else
        return 1;
}

// Create an array of all the valid exits from a room, determined using
// validRoom().

nomask int *validExits(int *iaCoords) {
    int i, *iaTmp, *iaRet;

    iaRet = ({});
    for(i = 1; i <= 10; i++) {
        iaTmp = exitCoords(iaCoords,i);
        if(validRoom(iaTmp))
            iaRet += ({i});
        continue;
    }
    return iaRet;
}

// Create a new room clone for the given co-ordinates.

nomask object cloneRoom(int *iaCoords) {
    string sFile, *saArr;
    int    i;
    object oOb;
    mixed  *xaTmp;

    xaTmp = mVirtualRooms[encodeCoords(iaCoords)];
// If there is no entry for the given co-ordinates, we can't clone a room.
    if(!xaTmp)   
        return 0;
// If a room object has already been created, return it.
    else if(xaTmp[ROOM])
        return xaTmp[ROOM];
    else
        sFile = mMapKeys[xaTmp[MAP_KEY]];
    if(sFile && file_size(sFile+".c") > 0) {
        catch(sFile->aLoadFun());
        if(find_object(sFile)) {
            oOb = clone_object(sFile);
            oOb->setVirtualCoords(iaCoords);
            saArr = m_indices(xaTmp[EXITS]);
            for(i = 0; i < sizeof(saArr); i++)
                oOb->addExit(saArr[i], xaTmp[EXITS][saArr[i]]);
            oOb->setupRoom();
            mVirtualRooms[encodeCoords(iaCoords)][ROOM] = oOb;
            return oOb;
        }
    }
}

// Set up an exit to any border room set for the given co-ordinates.

private void setupBorderExits(int *iaCoords) {
    string  sStr, *saArr;
    int     i;
    mapping mExits, mTmp;

    sStr = encodeCoords(iaCoords);
    mTmp = mBorderRooms[sStr];
    if(mTmp) {
        mExits = mVirtualRooms[sStr][EXITS];
        if(!mExits)
            mExits = ([]);
        saArr = m_indices(mTmp);
        for(i = 0; i < sizeof(saArr); i++)
            if(!mExits[saArr[i]])
                mExits[saArr[i]] = mTmp[saArr[i]];
        mVirtualRooms[sStr][EXITS] = mExits;
    }
}

// Set up an exit between two virtual rooms.
// Note: to avoid error, only one set of co-ordinates is passed. The other
// set are calculated from the exit direction given as the 2nd argument.

private void setupVirtualExit(int *iaCoordsA, int iAToB) {
    string  sCoordsA, sCoordsB;
    int     *iaCoordsB;
    mapping mExitsA, mExitsB;

    iaCoordsB = exitCoords(iaCoordsA, iAToB);
    sCoordsA = encodeCoords(iaCoordsA);
    sCoordsB = encodeCoords(iaCoordsB);
    if(mVirtualRooms[sCoordsA])
        mExitsA = mVirtualRooms[sCoordsA][EXITS];
    if(mVirtualRooms[sCoordsB])
        mExitsB = mVirtualRooms[sCoordsB][EXITS];

    if(!mExitsA || !mExitsB)
        return;

    else if(member(mExitsA, nameDir(iAToB)) ||
            member(mExitsB, nameDir(reverseDir(iAToB))))
        return;

    else {
        mExitsA[nameDir(iAToB)] = sprintf("%s,%d,%d,%d",
                                          sMaster,iaCoordsB[0],
                                          iaCoordsB[1],iaCoordsB[2]);
        mExitsB[nameDir(reverseDir(iAToB))] = sprintf("%s,%d,%d,%d",
                                                      sMaster,iaCoordsA[0],
                                                      iaCoordsA[1],
                                                      iaCoordsA[2]);
        mVirtualRooms[sCoordsA][EXITS] = mExitsA;
        mVirtualRooms[sCoordsB][EXITS] = mExitsB;
    }
}

// Set up the exits in the virtual area.

nomask void initialiseExits(int *iaCoords) {
    int i, *iaPoss;

    iaPoss = validExits(iaCoords);
    for(i = 0; i < sizeof(iaPoss); i++)
        setupVirtualExit(iaCoords, iaPoss[i]);
    setupBorderExits(iaCoords);
}

// Parse a level of the area from it's map.

nomask static void parseMap2(string *saArr, int iZ, int iY) {
    string sStr;
    int    i, iX;

#ifdef DEBUG
    tell_room(this_object(),
              "Parsing map for level "+iZ+", row "+iY+".\n");
#endif // DEBUG
    for(iX = 0; iX < iMaxX; iX++) {
        i = iX + (iY * iMaxX);
        if(saArr[i] != " ") {

            sStr = encodeCoords(({iX, iY, iZ}));
            initVirtualRoom(({iX, iY, iZ}));
            mVirtualRooms[sStr][MAP_KEY] = saArr[i];
        }
    }
}

private void parseMap(int iZ) {
    string *saArr;
    int    iY;

    if(mMaps[iZ])
        saArr = explode(mMaps[iZ], "");
    if(!saArr || !sizeof(saArr))
        return;
    
#ifdef DEBUG
    tell_room(this_object(),
              "Preparing to parse map for level "+iZ+".\n");
#endif // DEBUG

    for(iY = 0; iY < iMaxY; iY++)
        call_out("parseMap2", 0, saArr, iZ, iY);
}

// Set the dimensions of the virtual area.

void setAreaSize(int iX, int iY, int iZ) {
    iMaxX = iX;
    iMaxY = iY;
    iMaxZ = iZ;
}

// Set a key-file pair.

void setMapKey(string sKey, string sFile) {
    if(!mMapKeys)
        mMapKeys = ([]);

    if(strlen(sKey) != 1 || sKey == " ")
        return;
    else if(file_size(sFile+".c") < 0)
        return;
    else
        mMapKeys[sKey] = sFile;
}

// Set the map for a level of the area.

void setMap(int iZ, string sMap) {
    string sFile, *saArr, sKey, sValue, sTmp;
    int    i;

    if(!mMaps)
        mMaps = ([]);

    if(!iMaxX || !iMaxY || !iMaxZ || iZ < 0 || iZ >= iMaxZ)
        return;

    else if(file_size(sMap) > 0) {
        sFile = read_file(sMap);
        if(sFile) {
            sTmp = read_file(sMap+".key");
            if(sTmp)
                saArr = explode(sTmp, "\n");
            else
                saArr = ({});
            for(i = 0; i < sizeof(saArr); i++) {
                if(sscanf(saArr[i], "%s %s", sKey, sValue) != 2 &&
                   sscanf(saArr[i], "%s\t%s", sKey, sValue) != 2)
                    continue;
                else
                    setMapKey(sKey, sValue);
            }
            sMap = implode(explode(sFile, "\n"), "");
        }
    }

    if(strlen(sMap) != iMaxX * iMaxY)
        return;
    else {
        mMaps[iZ] = sMap;
#ifdef DEBUG
        tell_room(this_object(),
                  "Setting map for level "+iZ+".\n");
#endif // DEBUG
        parseMap(iZ);
    }
}
 
string queryMap(int iZ) {
    if(mMaps)
        return mMaps[iZ];
}

// Set a border room for the vitual area.

void setBorderRoom(int *iaCoords, string sDirToBorder, string sFile) {
    string sTmp;

    initBorderRoom(iaCoords);
    sTmp=encodeCoords(iaCoords);

    mBorderRooms[sTmp][sDirToBorder] = sFile;
}
    
mixed queryVirtualRoomInfo(int *iaCoords) {
    string sTmp;

    sTmp = encodeCoords(iaCoords); 
    return mVirtualRooms[sTmp];
}
        
mixed queryBorderRoomInfo(int *iaCoords) {
    string sTmp;
 
    sTmp = encodeCoords(iaCoords);
    return mBorderRooms[sTmp];
}

int testCoord(string sStr) {
    string  *saArr;
    int     i, iX, iY, iZ;
    mapping mTmp;
    mixed   *xaTmp;

    if(!sStr || sscanf(sStr, "%d,%d,%d", iX, iY, iZ) != 3)
        return 0;

    if((mTmp = mBorderRooms[sStr])) {
        printf("Found border room information for location %s:\n", sStr);
        saArr = m_indices(mTmp);
        for(i = 0; i < sizeof(saArr); i++)
            printf("File: %s, dir: %s\n\n", mTmp[saArr[i]], saArr[i]);
    }
    if((xaTmp = mVirtualRooms[sStr])) {
        printf("Found virtual room information for location %s:\n", sStr);
        if(xaTmp[ROOM])
            printf("Room object: %O\n", xaTmp[ROOM]);
        printf("Type: %s, file: %s\nExits: '",
               xaTmp[MAP_KEY], mMapKeys[xaTmp[MAP_KEY]]);
        saArr = m_indices(xaTmp[EXITS]);
        for(i = 0; i < sizeof(saArr); i++) {
            printf("%s: %s", saArr[i],
                   (stringp(xaTmp[EXITS][saArr[i]])?
                     xaTmp[EXITS][saArr[i]]:
                     encodeCoords(xaTmp[EXITS][saArr[i]])));
            if(i < sizeof(saArr)-1)
                write(", ");
        }
        write("'\n");
    }
    return 1;
}

int listRooms(string sStr) {
    switch(sStr) {
        case "virtual":
            printf("%-=78s\n", listArray(m_indices(mVirtualRooms), 0, 1));
            return 1;
        case "border":
            printf("%-=78s\n", listArray(m_indices(mBorderRooms), 0, 1));
            return 1;
        default:
            return 0;
    }
}

int gotoRoom(string sStr) {
    int    iX, iY, iZ;
    object oOb;
    mixed  *xaTmp;

    if(!sStr || sscanf(sStr, "%d,%d,%d", iX, iY, iZ) != 3)
        return 0;
    else if((xaTmp = mVirtualRooms[sStr])) {
        if(!(oOb = cloneRoom(({iX, iY, iZ})))) {
            printf("Room object for location '%s' could not be created.\n",
                   sStr);
            testCoord(sStr);
        }
        else
            this_player()->move_player("to "+sMaster+","+sStr, oOb);
        return 1;
    }
    else {
        printf("No virtual information found for lcoation '%s'.\n",
               sStr);
        return 1;
    }
}

// If the master is updated/reloaded, destruct all the cloned rooms.
void notify_destruct(object oOb) {
    string *saCoords;
    int    i;
    mixed  *xaTmp;

    saCoords = m_indices(mBorderRooms);
    for(i = 0; i < sizeof(saCoords); i++) {
        xaTmp = mVirtualRooms[saCoords[i]];
        if(xaTmp[ROOM])
            destruct(xaTmp[ROOM]);
    }
}

void reset(int iArg) {
    if(!iArg) {
        sMaster = "/"+file_name(this_object());
        if(!mBorderRooms)
            mBorderRooms = ([]);
        if(!mVirtualRooms)
            mVirtualRooms = ([]);
    }
}

void init() {
    add_action("testCoord", "test");
    add_action("listRooms", "list");
    add_action("gotoRoom",  "goto");
    printf("# of virtual rooms: %d\n# of border rooms: %d\n",
           m_sizeof(mVirtualRooms), m_sizeof(mBorderRooms));
}
