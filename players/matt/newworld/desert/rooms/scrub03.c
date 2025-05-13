inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Desert Border";
  long_desc =
    "    The earth is rather dry and barren here, much different from\n" +
    "the eastward grasslands. Off to the west a huge desert lies in\n" +
    "a basin formed by the rock formations and cliffs surrounding it.\n";

  dest_dir = ({
    NWDESERT + "rooms/waste03", "west",
    NWPLAINS + "rooms/plain29", "east",
    NWDESERT + "rooms/desert04", "north",
    NWDESERT + "rooms/desert03", "south",
  });

  items = ({
    "grasslands", "The grassy plains lie to the east",
    "desert", "The desert is huge and sparkles in the light of the sun",
    "cliffs", "Sheer rocky cliffs walling off the desert",
    "rock formations", "High rocky cliffs in which the desert is set",
  });
  clone_list = ({
    1, 1, "snake", NWDESERT + "monsters/redsnake", 0,
  });
  ::reset(arg);
  replace_program("/room/room");
}
