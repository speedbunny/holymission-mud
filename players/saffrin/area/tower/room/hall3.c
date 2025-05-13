inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Stairwell";
  long_desc=
      "You are in a dimly lit stairwell of the Mage Tower.  "+
      "There are several torches fixed to the walls around "+
      "you.  A warm inviting room is to the west, inviting you"+
      " to relax.  The mage library is located to the "+
      "east of you.  The special chamber room is to the "+
      "north.  From the south, there appears to be a horrid "+
      "looking dentatores.  At the center of the "+
      "stairwell, there is a large spiral staircase, leading both"+
      " up and down.\n";
  property=({ "has_fire" });
  dest_dir=({
      TOWER+"room/chamber", "north",
      TOWER+"room/dentist", "south",
      TOWER+"room/library", "east",
      TOWER+"room/sitroom", "west",
      TOWER+"room/hall4", "up",
      TOWER+"room/hall2", "down",
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

