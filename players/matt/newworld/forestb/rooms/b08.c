inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Bright Forest";
  long_desc =
    "    This is a small, crude path that leads southwest to what\n" +
    "looks like a clearing and north to an open space. The trees\n" +
    "here are somewhat densely-packed, making this place seem\n" +
    "darker than the rest of the forest. Brightly colored birds\n" +
    "chirp happily as they fly overhead.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b07", "north",
    NWFORESTB + "rooms/b04", "southwest",
  });

  items = ({
    "path", "A narrow space that has been cleared for walking upon",
    "trees", "Tall trees standing fairly close together",
    "forest", "You stand within a bright forest",
    "birds", "Small, quick birds flood the sky with song",
  });
  replace_program("/room/room");
}
