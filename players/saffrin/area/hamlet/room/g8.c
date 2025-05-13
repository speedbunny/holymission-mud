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
      "The path leads deeper into the graveyard towards the west.\n";
  dest_dir=({
      HAM+"room/g3", "west",
  });
  items=({
      "cobblestones", "Small gray stones making up a path",
      "tombstones", "Various shapes and sizes",
      "flowers", "tulips",
      "stairs", "Small marble stairs",
      "darkness", "You cannot see the darkness silly",
      "path", "A path made up of cobblestone",
  });
  clone_list=({      
      1, 2, "ghost", HAM+"npc/grghost", 0,
  });
  ::reset();
  replace_program("room/room");
}
