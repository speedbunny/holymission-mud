inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
    set_light(1);
    short_desc = "A wooded path";
    long_desc = 
         "You are walking on a small wooded path.  You notice a tent to the north of you "+
         "and laughter is coming from it.  You can hear music from all directions.  "+
         "The smell of incense and wood burning is distinct, soothing your mind.  "+
         "You feel part of your soul relax with the atmosphere.  "+
         "The path continues east and southwest of here.\n";
    dest_dir=({
      TINK+"room/tent12", "north",
      TINK+"room/path12", "east",
      TINK+"room/path14", "southwest",
    });
    items=({
      "path", "A path that runs through sparce woods",
      "tent", "A tent with coins sewn in the cloth",
      "coins", "Coins from various lands around the world",
      "woods", "Sparce woods made up of oak trees",
      "trees", "Large oak trees scattered about",
    });
    clone_list=({
          1, 1, "horse", TINK+"npc/horse", 0,
          1, 3, "cardinal", TINK+"npc/cardinal", 0,
    });
    ::reset();
    replace_program("room/room");
}
