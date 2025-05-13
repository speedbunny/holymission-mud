inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
    set_light(1);
    short_desc = "A wooded path";
    long_desc =
         "You are walking on a small wooded path.  You notice tents to the north and "+
         "to the south of you.  You can hear music and laughter from all directions.  "+
         "The smell of incense and wood burning is distinct, soothing your mind.  "+
         "You feel part of your soul relax with the aurora of the area.  "+
         "The path continues east and west.\n";
    dest_dir=({
      TINK+"room/tent8", "north",
      TINK+"room/tent7", "south",
      TINK+"room/path6", "east",
      TINK+"room/path4", "west",
    });
    items=({
      "path", "A path that runs through sparce woods",
      "woods", "Sparce woods made up of oak trees",
      "trees", "Large oak trees scattered about",
    });
    clone_list=({
          1, 2, "horse", TINK+"npc/horse", 0,
    });
    ::reset();
    replace_program("room/room");
}
