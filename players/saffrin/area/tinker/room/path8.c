inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
    set_light(1);
    short_desc = "A wooded path";
    long_desc = 
         "You are walking on a small wooded path.  There are woods all around you and "+
         "you can hear the cackles of laughter and merry making all around you.  "+
         "To the west you can hear the crackle of a fire and smell the sweetness of some "+
         "kind of wood burning.  "+
         "The path continues north and south from here.\n";
    dest_dir=({
      TINK+"room/path9", "north",
      TINK+"room/path7", "south",
      TINK+"room/fire", "west",
    });
    items=({
      "path", "A path that runs through sparce woods",
      "woods", "Sparce woods made up of oak trees",
      "trees", "Large oak trees scattered about",
    });
    clone_list=({
          1, 1, "horse", TINK+"npc/horse", 0,
          1, 2, "cardinal", TINK+"npc/cardinal", 0,
    });
    ::reset();
    replace_program("room/room");
}
