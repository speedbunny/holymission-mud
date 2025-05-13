inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
    set_light(1);
    short_desc = "A wooded path";
    long_desc =
         "You are walking on a wooded path.  In distance, you can hear the faint "+
         "hum of music.  The sound is mysteriously hypnotic and you feel your body "+
         "pull in its direction.  You smell wood burning somewhere and it warms your "+
         "soul.  It feel to you that something magical is near.  "+
         "Joy's Park is to the west of you.  "+
         "The path continues north and southeast of here.\n";
    dest_dir=({
      TINK+"room/path14", "north",
      TINK+"room/joy4", "west",
      TINK+"room/path2", "southeast",
    });
    items=({
      "path", "A path that runs through sparce woods",
      "woods", "Sparce woods made up of oak trees",
      "trees", "Large oak trees scattered about",
    });
    clone_list=({
          1, 1, "cardinal", TINK+"npc/cardinal", 0,
          1, 1, "horse", TINK+"npc/horse", 0,
    });
    ::reset();
    replace_program("room/room");
}
