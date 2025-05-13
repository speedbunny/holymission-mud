inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Stage wings";
  long_desc = 
      "You are standing in the wings of the theatre directly to the side of the"+
      " actual stage.  There are several ropes that hanging from high above in "+
      "the catwalks.  There is a small rack to the west with a few costumes on it.  "+
      "A small wooden table rests along the east wall with props scattered on"+
      " top of it.  Several sandbags lay all around with sand spilling out of them."+
      "  A few long planks cover holes in the floor.\n";
  dest_dir=({
      HAM+"room/droom13", "north",
      HAM+"room/stage", "south",
  });
  items=({
      "floor", "It is filthy and several holes are covered with planks",
      "ropes", "Hanging from the ceiling above",
      "ceiling", "Several ropes hang from above.  Some have sandbags attached",
      "planks", "Several wooden planks covering several holes in the floor",
      "catwalks", "Several wooden riggings that run up and above the stage",
      "rack", "A rack filled with costumes",
      "table", "A table with props on top",
      "props#costumes", "Being used for a play",
      "sandbags", "Large bags of sand that are spilling",
      "sand", "White little grains of sand",
  });
  clone_list=({
     1, 6, "player", HAM+"npc/player", 0,
  });
  ::reset();
  replace_program("room/room");
}
