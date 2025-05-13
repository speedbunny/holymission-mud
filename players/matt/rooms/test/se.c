inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Test SE";
  long_desc =
    "    This is Matt's Test Room, SOUTHEAST.\n";

  dest_dir = ({
    ROOM + "test/e", "north",
    ROOM + "test/s", "west",
    ROOM + "test/c", "northwest",    
  });
  replace_program("/room/room");
}
