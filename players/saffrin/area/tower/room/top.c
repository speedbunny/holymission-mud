inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Top of the Mage Tower";
  long_desc=
      "You are at the top of the most unusual stairwell of the mage tower.  "+
      "You are out in the fresh air with battlements to the north, south, "+
      "east, and west of you.  Crystals shine at you from all directions.  "+
      "There are fluffy white clouds in the blue sky above.  The staircase leads "+
      "down into the mage tower.\n";
  dest_dir=({
      TOWER+"room/b1", "north",
      TOWER+"room/b3", "south",
      TOWER+"room/b4", "east",
      TOWER+"room/b2", "west",
      TOWER+"room/hall9", "down",
  });
  items=({ 
      "stairwell","A stairwell for a spiral staircase",
      "staircase","A winding spiral staircase",
      "walls", "The walls are made from glass",
      "plants", "Various kinds of plants",
      "light", "Glaring bright light",
      "battlements", "Crystal battlements",
       "crystals", "Crystals that reflex the sunlight, causing it to appears in all directions",
      "crystal", "Crystal making up battlements",
      "sky", "Blue sky with white clouds",
      "clouds", "Fluffy white clouds",
  });
  ::reset();
  replace_program("room/room");
}

