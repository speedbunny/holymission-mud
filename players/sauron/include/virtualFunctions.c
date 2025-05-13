// Virtual area functions file.                 Written by Sauron, 220897.

// General funs used throughout the virtual area system:

#ifndef __VIRTUAL_FUNCTIONS_H__

#define __VIRTUAL_FUNCTIONS_H__

#include "/players/sauron/include/virtual.h"

// Encode a set of coordinates.

string encodeCoords(int *iaCoords) {
    return sprintf("%d,%d,%d",iaCoords[0],iaCoords[1],iaCoords[2]);
}

// Decode a set of coordinates.

int *decodeCoords(string sCoords) {
    int *iaCoords;

    iaCoords=allocate(3);
    sscanf(sCoords,"%d,%d,%d",iaCoords[0],iaCoords[1],iaCoords[2]);
    return iaCoords;
}

// Return the def corresponding to a dir string.

int dirName(string sName) {
    switch(sName) {
        case "west"     : return WEST;
        case "northwest": return NORTHWEST;
        case "north"    : return NORTH;
        case "northeast": return NORTHEAST;
        case "east"     : return EAST;
        case "southeast": return SOUTHEAST;
        case "south"    : return SOUTH;
        case "southwest": return SOUTHWEST;
        case "up"       : return UP;
        case "down"     : return DOWN;
    }
}

// Return the string corresponding to a dir def.

string nameDir(int iDir) {
    switch(iDir) {
        case WEST     : return "west";
        case NORTHWEST: return "northwest";
        case NORTH    : return "north";
        case NORTHEAST: return "northeast";
        case EAST     : return "east";
        case SOUTHEAST: return "southeast";
        case SOUTH    : return "south";
        case SOUTHWEST: return "southwest";
        case UP       : return "up";
        case DOWN     : return "down";
    }
}

// Return the change in co-ords corresponding to an exit.

private int *dirVect(int iDir) {
    switch(iDir) {
        case WEST     : return ({-1, 0, 0});
        case NORTHWEST: return ({-1,-1, 0});
        case NORTH    : return ({ 0,-1, 0});
        case NORTHEAST: return ({ 1,-1, 0});
        case EAST     : return ({ 1, 0, 0});
        case SOUTHEAST: return ({ 1, 1, 0});
        case SOUTH    : return ({ 0, 1, 0});
        case SOUTHWEST: return ({-1, 1, 0});
        case UP       : return ({ 0, 0, 1});
        case DOWN     : return ({ 0, 0,-1});
    }
}

// Reverse a dir.

int reverseDir(int iDir) {
    switch(iDir) {
        case WEST     : return EAST;
        case NORTHWEST: return SOUTHEAST;
        case NORTH    : return SOUTH;
        case NORTHEAST: return SOUTHWEST;
        case EAST     : return WEST;
        case SOUTHEAST: return NORTHWEST;
        case SOUTH    : return NORTH;
        case SOUTHWEST: return NORTHEAST;
        case UP       : return DOWN;
        case DOWN     : return UP;
    }
}

// Calculate the co-ords of a room based on the co-ords here.

int *exitCoords(int *iaHere,int iDir) {
    int *iaRet,*iaTmp;

    iaRet=allocate(3);
    iaTmp=dirVect(iDir);
    iaRet[0]=iaHere[0]+iaTmp[0];
    iaRet[1]=iaHere[1]+iaTmp[1];
    iaRet[2]=iaHere[2]+iaTmp[2];

    return iaRet;
}

#endif // __VIRTUAL_FUNCTIONS_H__
