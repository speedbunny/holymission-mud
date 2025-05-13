inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Test W";
  long_desc =
    "    This is Matt's Test Room, WEST.\n";

  dest_dir = ({
    ROOM + "test/nw", "north",
    ROOM + "test/n", "northeast",
    ROOM + "test/c", "east",
    ROOM + "test/s", "southeast",
    ROOM + "test/sw", "south",
  });
  replace_program("/room/room");
}
