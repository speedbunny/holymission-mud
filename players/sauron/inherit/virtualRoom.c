// Virtual area room.                           Written by Sauron, 220897.

inherit "/room/room";

#if 0
#include "/players/sauron/include/include.h"
#else
#define PO		previous_object()
#define TP		this_player()
#define APPR(o)		(int)o->query_immortal()
#define TESTP(o)	(string)o->query_testchar()
#endif // 0
#include "/players/sauron/include/virtual.h"
#include "/players/sauron/include/virtualFunctions.c"
#include <sys_vt100.h>

private string  sMaster;
private int     *iaVirtualCoords;
private mapping mExits;

mapping queryExits() {
    return mExits;
}

void setVirtualCoords(int *iaCoords) {
    sMaster = "/"+fileName(PO, 1);
    iaVirtualCoords = iaCoords;
}

int *queryVirtualCoords() {
    return iaVirtualCoords;
}

void addExit(string sDir,string sFile) {
    if(!mExits)
        mExits = ([]);
    mExits[sDir] = allocate(2);
    mExits[sDir][0] = sFile;
}

varargs mapping queryVirtualExits(int iFlag) {
    string  *saArr, sTmp;
    int     i, iX, iY, iZ;
    mapping mRet;

    if(!mExits)
        mExits = ([]);
    saArr = m_indices(mExits);
    mRet = ([]);
    for(i = 0; i < sizeof(saArr); i++) {
        if(sscanf(mExits[saArr[i]][0],
                  "%s,%d,%d,%d",
                  sTmp, iX, iY, iZ) == 4) {
            if(!iFlag || sTmp == sMaster)
                mRet[saArr[i]] = mExits[saArr[i]][0];
        }
        else
            continue;
    }
    return mRet;
}

static void checkExits() {
    string *saDirs, sTmp;
    int    i, j, iX, iY, iZ;
    object oOb;

    if(!dest_dir)
        dest_dir = ({});
    if(!mExits)
        mExits = ([]);

    saDirs = m_indices(mExits);
    for(i = 0; i < sizeof(saDirs); i++) {
        if(sscanf(mExits[saDirs[i]][0],
                  "%s,%d,%d,%d",
                  sTmp, iX, iY, iZ) == 4) {
            if(!mExits[saDirs[i]][1]) {
                sTmp->initialiseExits(({iX, iY, iZ}));
                mExits[saDirs[i]][1] = sTmp->cloneRoom(({iX, iY, iZ}));
            }
            oOb = mExits[saDirs[i]][1];
            j = member_array(saDirs[i], dest_dir);
            if(j == -1)
                dest_dir += ({file_name(oOb), saDirs[i]});
            else
                dest_dir[j-1] = file_name(oOb);
        }
        else {
            j = member_array(saDirs[i], dest_dir);
            if(j == -1)
                dest_dir += ({mExits[saDirs[i]][0], saDirs[i]});
            else
                dest_dir[j-1] = mExits[saDirs[i]][0];
        }
    }
}

int move(string sStr) {
    checkExits();

    return ::move(sStr);
}

void long(string sStr) {
    if(!sStr && (APPR(TP) || TESTP(TP)))
        printf("%s%|'-'*s\n%s",
               VT_TA_B,   
               78,
               sprintf(" Virtual location:  %s,%s ",
                       sMaster,
                       encodeCoords(queryVirtualCoords())),
               VT_RESET);
    return ::long(sStr);
}
            
#if 0
void reset(int iArg) {
    ::reset(iArg);
}
#endif // 0

void init() {
    checkExits();

    ::init();
}
