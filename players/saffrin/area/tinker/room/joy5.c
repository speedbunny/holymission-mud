inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
    set_light(2);
    short_desc="Joy's Park";
    long_desc=
         "You are standing along the south edge of Joy's Park.  There is a small "+
         "bird bath made from white marble standing here.  It is surrounded "+
         "by small white stones.  A few birds are chirpping nearbye.  You can "+
         "feel the warm, tender sun on your face.\n";
    dest_dir = ({
      TINK+"room/joy12", "north",
      TINK+"room/joy4", "east",
      TINK+"room/joy6", "west",
    });
    items =({
      "bath", "A small white marble bird bath",
      "bird bath", "A small white marble bird bath",
      "stones", "Small white stones decorating the bird bath",
      "sun", "ARGH!!!!!!  You will burn your eyes out!!!!!",
    });
    clone_list=({
          1, 3, "cardinal", TINK+"npc/cardinal", 0,
    });
    ::reset();
    replace_program("room/room");
}
