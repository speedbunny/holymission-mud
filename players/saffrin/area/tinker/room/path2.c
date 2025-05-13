inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
    set_light(1);
    short_desc = "A wooded path";
    long_desc = 
         "You are walking on a small wooded path.  You notice tents to the north and "+
         "south of you.  You can hear music and laughter from all directions.  "+
         "The smell of incense and wood burning is distinct, soothing your mind.  "+
         "You feel your soul relax with the atmosphere.  "+
         "The path continues east and northwest of here.\n";
    dest_dir=({
      TINK+"room/tent2", "north",
      TINK+"room/tent1", "south",
      TINK+"room/path3", "east",
      TINK+"room/path1", "northwest",
    });
    items=({
      "tents", "Tents with coins sewn into its cloth",
      "coins", "Coins from various places around the world",
      "path", "A path that runs through sparce woods",
      "woods", "Sparce woods made up of oak trees",
      "trees", "Large oak trees scattered about",
    });
    clone_list=({
          1, 1, "cardinal", TINK+"npc/cardinal", 0,
    });
    ::reset();
    replace_program("room/room");
}
