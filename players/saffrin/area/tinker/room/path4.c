inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
    set_light(1);
    short_desc = "A wooded path";
    long_desc = 
         "You are walking on a small wooded path.  You notice to the north and "+
         "to the south of you are tents.  You can hear music and laughter from all directions.  "+
         "The smell of incense and wood burning is distinct, soothing your mind.  "+
         "You feel part of your soul relax with the atmosphere.  "+
         "The path continues east and west of here.\n";
    dest_dir=({
      TINK+"room/tent6", "north",
      TINK+"room/tent5", "south",
      TINK+"room/path5", "east",
      TINK+"room/path3", "west",
    });
    items=({
      "tents", "Tents with coins sewn in the cloth",
      "coins", "Coins from various places around the world",
      "path", "A path that runs through sparce woods",
      "woods", "Sparce woods made up of oak trees",
      "trees", "Large oak trees scattered about",
    });
    clone_list=({
          1, 1, "horse", TINK+"npc/horse", 0,
    });
    ::reset();
    replace_program("room/room");
}
