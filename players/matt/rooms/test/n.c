inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Test N";
  long_desc =
    "    This is Matt's Test Room, NORTH.\n";

  dest_dir = ({
    ROOM + "test/ne", "east",
    ROOM + "test/e", "southeast",
    ROOM + "test/c", "south",
    ROOM + "test/w", "southwest",
    ROOM + "test/nw", "west",
  });
  replace_program("/room/room");
}
