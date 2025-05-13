inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Forest Entrance";
  long_desc =
    "    You stand at the entrance to a dark forest. Tall black\n" +
    "trees surround you, looming overhead and threatening to\n" +
    "block out all light with their thick branches. To the east\n" +
    "is North Road, and to the west the forest gets darker.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a02", "west",
    NWROAD + "rooms/road03", "east",
  });

  items = ({
    "forest", "An eerie forest. You get a sudden chill",
    "trees", "Tall, withered trees",
    "light", "The light is somewhat dim here",
    "branches", "Gnarled tree branches overhead",
    "road", "You can make out North Road to the east",
  });
  replace_program("/room/room");
}
