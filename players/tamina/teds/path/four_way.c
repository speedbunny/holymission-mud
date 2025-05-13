inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  set_light(1);
  short_desc = "Four Way Intersection";
  long_desc =
    "Here the north-south cobblestone path intercepts a\n"+
    "east-west dirt path. This path leads through the\n"+
    "Dread Forest. The Dread Forest is renowned for its\n"+
    "many evil monsters. It is the proving ground for\n"+
    "new Knights of the Round Table.\n";

  dest_dir = ({
      TPATH + "path3","south",
      TPATH + "path4","north",
      TFOREST + "rmE", "east",
      TFOREST + "rmD","west",
    });

  items = ({
  "forest",
"This is the Dread Forest.  It surrounds you with its dark, foreboding "+
"trees.  You understand why this is the testing ground for novice knights "+
"of the famous Round Table..",
  });

    ::reset();

    replace_program("room/room");
}
