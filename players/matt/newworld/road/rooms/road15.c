inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Mountain Road";
  long_desc =
    "    Here the terrain is extremely rocky, and the road is at\n" +
    "a drastic slope, upwards into the mountains directly north\n" +
    "of you, and downwards into the highlands to the south. The\n" +
    "air is much colder here than in the southern lands, and\n" +
    "other than the occasional howling of the wind, it is\n" +
    "strangely silent.\n";

  dest_dir = ({
    NWROAD + "rooms/road16", "north",
    NWROAD + "rooms/road10", "south",
  });

  items = ({
    "mountains", "The Mountains of Sanity are extremely close now",
    "road", "This is a rocky north-south section of North Road",
    "highlands", "You see a vast stretch of hilly country",
  });
  replace_program("/room/room");
}
