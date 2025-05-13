inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Test NE";
  long_desc =
    "    This is Matt's Test Room, NORTHEAST.\n";

  dest_dir = ({
    ROOM + "test/e", "south",
    ROOM + "test/c", "southwest",
    ROOM + "test/n", "west",
  });
  replace_program("/room/room");
}
