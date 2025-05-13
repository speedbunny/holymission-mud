inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  if(arg)return;
    set_light(1);
    short_desc = "A wooded path";
    long_desc =
         "You are walking on a wooded path.  In the distance, you can hear the faint hum of music.  "+
         "The sound is mysteriously hypnotic and you feel your body pull in its direction.  "+
         "You can smell wood and incense burning somewhere and the smell warms your soul.  "+
         "It feels to you that something magical is nearby.  "+
         "Joy's park is to the west of you.  "+
         "The path continues south and northeast from here.\n";
    dest_dir=({
      TINK+"room/path1", "south",
      TINK+"room/joy3", "west",
      TINK+"room/path13", "northeast",
    });
    items=({
      "path", "A path that runs through sparce woods",
      "woods", "Sparce woods made up of oak trees",
      "trees", "Large oak trees scattered about",
    });
    clone_list=({
          1, 3, "horse", TINK+"npc/horse", 0,
    });
    ::reset();
    replace_program("room/room");
}
