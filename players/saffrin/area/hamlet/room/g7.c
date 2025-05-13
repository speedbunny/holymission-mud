inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(0);
  short_desc = "Denmark's Graveyard";
  long_desc = 
      "You are walking along a small cobblestoned path that is worn from age.  "+
      "There are tombstones of various sizes and shapes lined up in neat rows "+
      "all around you.  There appears to be flowers of some kind in front of a large"+
      " mausoleum.  In the distance, the wind howls loudly at the darkness around you.  "+
      "The path leads deeper into the graveyard towards the north and northeast.\n";
  dest_dir=({
      HAM+"room/g6", "north",
      HAM+"room/g9", "northeast",
  });
  items=({
      "cobblestones", "Small gray stones making up a path",
      "tombstones", "Various shapes and sizes",
      "flowers", "Violets",
      "mausoleum", "It is a large marble mausoleum with letters engraved on it",
      "letters", "They read: Here lies Yorick, most adored court jester",
      "stairs", "Small marble stairs",
      "darkness", "You cannot see the darkness silly",
      "path", "A path made up of cobblestone",
  });
  clone_list=({      
      1, 1, "yorick", HAM+"npc/yorick", 0,
  });
  ::reset();
  replace_program("room/room");
}
