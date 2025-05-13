inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
    set_light(2);
    short_desc="Joy's Park";
    long_desc =
         "You are standing in the southeast corner of Joy's Park.  There is a small "+
         "marble bench here.  You can hear the trickling of water coming from the "+
         "northwest.  The sun is shining very brightly and sending a warm glow "+
         "to all that inhabit the park.  A tinker camp is to the east of here.\n";
    dest_dir = ({
      TINK+"room/joy3", "north",
      TINK+"room/path1", "east", 
      TINK+"room/joy5", "west",
    });
    items =({
      "bench", "A small white mable bench",
      "sun", "ARGH!!!!!  Don't look at the sun!  You will burn your eyes out!",
    });
    ::reset();
    replace_program("room/room");
}
