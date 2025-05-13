inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Test S";
  long_desc =
    "    This is Matt's Test Room, SOUTH.\n";

  dest_dir = ({
    ROOM + "test/c", "north",
    ROOM + "test/e", "northeast",
    ROOM + "test/se", "east",
    ROOM + "test/sw", "west",
    ROOM + "test/w", "northwest",    
  });
  replace_program("/room/room");
}
