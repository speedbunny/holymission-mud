inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Stairwell";
  long_desc=
      "You are in the most unusual stairwell of the mage tower.  "+
      "There are quartz walls to the south, east, and west of you.  "+
      "Through the quartz you can see various kinds of plants, growing "+
      "in a proud green glory.  To the north, there is a doorway made "+
      "from a bunch of ivy.  Bright light shines through the quartz.  "+  
      "At the center of the stairwell, there is a large spiral"+
      " staircase, leading both up and down.\n";
  dest_dir=({
      TOWER+"room/garden1", "north",
      TOWER+"room/top", "up",
      TOWER+"room/hall8", "down",
  });
  items=({ 
      "stairwell","A stairwell for a spiral staircase",
      "staircase","A winding spiral staircase",
      "walls", "The walls are made from quartz",
      "plants", "Various kinds of plants",
      "light", "Glaring bright light",
      "ivy", "An ivy doorway",
      "doorway", "A doorway made from ivy",
  });
  ::reset();
  replace_program("room/room");
}

