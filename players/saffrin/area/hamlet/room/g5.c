inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(0);
  short_desc = "Denmark's Graveyard";
  long_desc = 
      "You are walking along a small cobblestoned path that is worn from age.  "+
      "There are tombstones of various sizes and shapes lined up in neat rows "+
      "all around you.  There appears to be flowers of some kind in front of one of"+
      " graves.  In the distance, the wind howls loudly at the darkness around you.  "+
      "The path leads deeper into the graveyard towards the north and east.\n";
  dest_dir=({
      HAM+"room/g4", "north",
      HAM+"room/g6", "east",
  });
  items=({
      "cobblestones", "Small gray stones making up a path",
      "tombstones", "Various shapes and sizes",
      "flowers", "Orchids",
      "stairs", "Small marble stairs",
      "darkness", "You cannot see the darkness silly",
      "path", "A path made up of cobblestone",
  });
  ::reset();
  replace_program("room/room");
}
