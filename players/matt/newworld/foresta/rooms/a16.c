inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Windy Clearing";
  long_desc =
    "    The howl of the wind is almost deafening in the clearing\n" +
    "you now stand in. You find it difficult to move against its\n" +
    "powerful breath, which continually changes direction and\n" +
    "makes everything around you sway and bend sickeningly.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a12", "southeast",
  });
  
  items = ({
    "clearing", "The clearing seems to be moving from the wind",
  });
  
  clone_list = ({
    1, 2, "walker", NWFORESTA + "monsters/windwalker", 0,
  });
  ::reset(arg);
  replace_program("/room/room");
}
