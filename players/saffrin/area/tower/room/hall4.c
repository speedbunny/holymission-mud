inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Stairwell";
  long_desc=
      "You are in a dimly lit stairwell of the Mage Tower.  "+
      "There are several torches fixed to the walls around "+
      "you.  This is the special fire sign floor of the tower "+
      "where research on zodiac signs can take place.  To the "+
      "north is the Aries room.  The Leo room is the east and the "+
      "Sagittarius room is to the west.  The guest bedroom is to the "+
      "south.  At the center of the "+
      "stairwell, there is a large spiral staircase, leading both"+
      " up and down.\n";
  property=({ "has_fire" });
  dest_dir=({
      TOWER+"room/aries", "north",
      TOWER+"room/guesbed", "south",
      TOWER+"room/leo", "east",
      TOWER+"room/sagitt", "west",
      TOWER+"room/hall5", "up",
      TOWER+"room/hall3", "down",
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

