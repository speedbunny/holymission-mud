inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
    set_light(2);
    short_desc="Joy's Park";
    long_desc =
         "You are standing along the eastern edge of Joy's park.  The green grass "+
         "under your feet appears wet with dew.  You can smell the sweet "+
         "fragrance of flowers from somewhere nearby.  The atmosphere has a calming effect.  "+
         "There is a tinker camp to the east.\n";
    dest_dir = ({
      TINK+"room/joy2", "north",
      TINK+"room/joy4", "south",
      TINK+"room/path14", "east",
      TINK+"room/joy12", "west",
    });
     items =({
      "grass", "Green grass wet with dew",
      "dew", "Moist droplets covering the blade of green grass",
      "droplets", "Droplets of dew",
    });
    clone_list=({
          1, 2, "robin", TINK+"npc/robin", 0,
    });
    ::reset();
    replace_program("room/room");
}
