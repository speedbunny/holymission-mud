inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
    set_light(1);
    short_desc = "A wooded path";
    long_desc = 
         "You are walking on a small wooded path.  There are woods all around you and "+
         "you can hear music in the distance.  The cackles of laugther and merry making "+
         "echo all around you.  You can smell the sweetness of a fire burning from "+
         "the northwest.  "+
         "The path continues north and south of here.\n";
    dest_dir=({
      TINK+"room/path8", "north",
      TINK+"room/path6", "south",
    });
    items=({
      "path", "A path that runs through sparce woods",
      "woods", "Sparce woods made up of oak trees",
      "trees", "Large oak trees scattered about",
    });
    clone_list=({
          1, 2, "horse", TINK+"npc/horse", 0,
          1, 1, "cardinal", TINK+"npc/cardinal", 0,
    });
    ::reset();
    replace_program("room/room");
}
