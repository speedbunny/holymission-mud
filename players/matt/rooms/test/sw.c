inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Test SW";
  long_desc =
    "    This is Matt's Test Room, SOUTHWEST.\n";

  dest_dir = ({
    ROOM + "test/w", "north",
    ROOM + "test/c", "northeast",
    ROOM + "test/s", "east",
  });
  replace_program("/room/room");
}
