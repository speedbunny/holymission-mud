inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Stairwell";
  long_desc=
      "You are in a dimly lit stairwell of the Mage Tower.  "+
      "There are several torches fixed to the walls around "+
      "you.  This is the special water sign floor of the tower "+
      "where research on zodiac signs can take place.  To the "+
      "north is the Cancer room.  The Scorpio room is the east and the "+
      "Pisces room is to the west.  Yorel's bedroom is to the "+
      "south.  At the center of the "+
      "stairwell, there is a large spiral staircase, leading both"+
      " up and down.\n";
  dest_dir=({
      TOWER+"room/cancer", "north",
      TOWER+"room/yorbed", "south",
      TOWER+"room/scorpio", "east",
      TOWER+"room/pisces", "west",
      TOWER+"room/hall8", "up",
      TOWER+"room/hall6", "down",
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

