// Virtual area functions file.			Written by Sauron, 220897.

#include "/players/sauron/include/virtual.h"

// General funs used throughout the virtual area system:

// Encode a set of coordinates.

string encode_coords(int *coords) {
  return sprintf("%d,%d,%d",coords[0],coords[1],coords[2]);
}

// Decode a set of coordinates.

int *decode_coords(string str) {
  int *ret;

  ret=allocate(3);
  sscanf(str,"%d,%d,%d",ret[0],ret[1],ret[2]);
  return ret;
}

// Return the def corresponding to a dir string.

int dir_name(string name) {
  switch(name) {
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

string name_dir(int dir) {
  switch(dir) {
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

private int *dir_vect(int dir) {
  switch(dir) {
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

int reverse_dir(int dir) {
  switch(dir) {
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

int *exit_coords(int *here,int dir) {
  int *ret,*tmp;

  ret=allocate(3);
  tmp=dir_vect(dir);
  ret[0]=here[0]+tmp[0];
  ret[1]=here[1]+tmp[1];
  ret[2]=here[2]+tmp[2];

  return ret;
}
