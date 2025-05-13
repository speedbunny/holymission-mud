inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Stairwell";
  long_desc=
      "You are in a dimly lit stairwell of the Mage Tower.  "+
      "There are several torches fixed to the walls around "+
      "you.  This is the special earth sign floor of the tower "+
      "where research on zodiac signs can take place.  To the "+
      "north is the Taurus room.  The Virgo room is the east and the "+
      "Capricorn room is to the west.  Yorel's workroom is to the "+
      "south.  At the center of the "+
      "stairwell, there is a large spiral staircase, leading both"+
      " up and down.\n";
  property=({ "has_fire" });
  dest_dir=({
      TOWER+"room/taurus", "north",
      TOWER+"room/yorwork", "south",
      TOWER+"room/virgo", "east",
      TOWER+"room/capri", "west",
      TOWER+"room/hall7", "up",
      TOWER+"room/hall5", "down",
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

