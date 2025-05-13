inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Test NW";
  long_desc =
    "    This is Matt's Test Room, NORTHWEST.\n";

  dest_dir = ({
    ROOM + "test/n", "east",
    ROOM + "test/c", "southeast",
    ROOM + "test/s", "southwest",
  });
  replace_program("/room/room");
}
