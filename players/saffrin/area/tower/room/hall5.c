inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Stairwell";
  long_desc=
      "You are in a dimly lit stairwell of the Mage Tower.  "+
      "There are several torches fixed to the walls around "+
      "you.  This is the special air sign floor of the tower "+
      "where research on zodiac signs can take place.  To the "+
      "north is the Gemini room.  The Libra room is the east and the "+
      "Aquarius room is to the west.  The privy is to the "+
      "south.  At the center of the "+
      "stairwell, there is a large spiral staircase, leading both"+
      " up and down.\n";
  property=({ "has_fire" });
  dest_dir=({
      TOWER+"room/gemini", "north",
      TOWER+"room/privy", "south",
      TOWER+"room/libra", "east",
      TOWER+"room/aquari", "west",
      TOWER+"room/hall6", "up",
      TOWER+"room/hall4", "down",
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

