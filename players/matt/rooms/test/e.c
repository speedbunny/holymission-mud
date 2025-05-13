inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Test E";
  long_desc =
    "    This is Matt's Test Room, EAST.\n";

  dest_dir = ({
    ROOM + "test/ne", "north",
    ROOM + "test/se", "south",
    ROOM + "test/s", "southwest",
    ROOM + "test/c", "west",
    ROOM + "test/n", "northwest",    
  });
  replace_program("/room/room");
}
