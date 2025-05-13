inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Stairwell";
  long_desc=
      "You are in a dimly lit stairwell of the Mage Tower.  "+
      "There are several torches fixed to the walls around "+
      "you.  The mage kitchen is to the west, inviting you"+
      " to come cook.  Cherlindrea's workroom is located to the "+
      "east of you and her bedroom is to the south.  "+
      "To the north, there is a large dining hall for all the mages "+
      "to eat in.  At the center of the "+
      "stairwell, there is a large spiral staircase, leading both"+
      " up and down.\n";
  property=({ "has_fire" });
  dest_dir=({
      TOWER+"room/dinroom", "north",
      TOWER+"room/cherbed", "south",
      TOWER+"room/cherwork", "east",
      TOWER+"room/kitchen", "west",
      TOWER+"room/hall9", "up",
      TOWER+"room/hall7", "down",
  });
  items=({ 
      "stairwell","A stairwell for a spiral staircase",
      "staircase","A winding spiral staircase",
      "floor","The floor is tiled with dark, green jade",
      "torches", "Brass torches with flicking flames",
      "flames","Flicking orange flames",
  });
  ::reset();
  replace_program("room/room");
}

