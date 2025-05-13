// Virtual area border room.                    Written by Sauron, 220897.

inherit "/room/room";

#include "/players/sauron/include/virtual.h"
#include "/players/sauron/include/virtualFunctions.c"

private mapping mExits;

void addExit(string sDir,string sFile) {
    if(!mExits)
        mExits=([]);
    mExits[sDir]=allocate(2);
    mExits[sDir][0]=sFile;
}

void checkExits() {
    string *asDirs,sMaster;
    int i,j,iX,iY,iZ;
    object oOb;

    if(!dest_dir)
        dest_dir=({});
    if(!mExits)
        mExits=([]);

    asDirs=m_indices(mExits);
    for(i=0;i<sizeof(asDirs);i++) {
        if(sscanf(mExits[asDirs[i]][0],"%s,%d,%d,%d",sMaster,iX,iY,iZ)==4) {
            if(!mExits[asDirs[i]][1]) {
                sMaster->initialiseExits(({iX,iY,iZ}));
                mExits[asDirs[i]][1]=sMaster->cloneRoom(({iX,iY,iZ}));
            }
            oOb=mExits[asDirs[i]][1];
            j=member_array(asDirs[i],dest_dir);
            if(j==-1)
                dest_dir+=({file_name(oOb),asDirs[i]});
            else
                dest_dir[j-1]=file_name(oOb);
        }
        else {
            j=member_array(asDirs[i],dest_dir);
            if(j==-1)
                dest_dir+=({mExits[asDirs[i]][0],asDirs[i]});
            else
                dest_dir[j-1]=mExits[asDirs[i]][0];
        }
    }
}

int move(string sStr) {
    checkExits();

    return ::move(sStr);
}

void init() {
    checkExits();

    ::init();
}
