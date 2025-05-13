inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Test C";
  long_desc =
    "    This is Matt's Test Room, CENTER.\n";

  dest_dir = ({
    ROOM + "test/n", "north",
    ROOM + "test/ne", "northeast",
    ROOM + "test/e", "east",
    ROOM + "test/se", "southeast",
    ROOM + "test/s", "south",
    ROOM + "test/sw", "southwest",
    ROOM + "test/w", "west",
    ROOM + "test/nw", "northwest",    
  });
  replace_program("/room/room");
}
