inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Dark Forest";
  long_desc =
    "    A white mist floats through here, drifting around your\n" +
    "ankles and chilling you with an almost unnatural cold. This\n" +
    "place is very dark; the branches of the surrounding trees\n" +
    "completely block out the sunlight.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a03", "north",
    NWFORESTA + "rooms/a02", "southeast",
  });

  items = ({
    "mist", "Cold white mist, hanging low near the ground",
    "branches", "Thick, wasted braches over your head",
    "trees", "Tall withered trees",
  });
  replace_program("/room/room");
}
