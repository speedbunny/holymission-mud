inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
    set_light(1);
    short_desc = "A wooded path";
    long_desc =
         "You are walking on a small wooded path.  There are woods all around you and "+
         "you can hear music in the distance.  The cackles of laughter and merry making "+
         "echo all around you.  To the north you see a huge tent, decorated to stand out.  "+
         "From somewhere, you can smell a sweet fire burning.  "+
         "The path continues south and west.\n";
    dest_dir=({
      TINK+"room/kingtent", "north",
      TINK+"room/path8", "south",
      TINK+"room/path10", "west",
    });
    items=({
      "path", "A path that runs through sparce woods",
      "woods", "Sparce woods made up of oak trees",
      "trees", "Large oak trees scattered about",
      "tent", "A large tent that had coins sewn into its cloth",
      "cloth", "Brown cloth with coins sewn in it",
      "coins", "Coins collect from various lands around the world",
    });
    ::reset();
    replace_program("room/room");
}
