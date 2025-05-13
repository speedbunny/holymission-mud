inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "City Road";
  long_desc =
    "    You are rather close to the city, and here the road turns\n" +
    "west towards the city itself and southeast back to the fork in\n" +
    "the road. The wind is rather strong here, and it blows against\n" +
    "you with its cold breath.\n";

  dest_dir = ({
    NWROAD + "rooms/road14", "west",
    NWROAD + "rooms/road12", "southeast",
  });

  items = ({
    "road", "This is a well-used path into the city",
  });
  replace_program("/room/room");
}
