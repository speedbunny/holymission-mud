inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Desert Border";
  long_desc =
    "    Scrub brush is abundant in the dry earth, a drastic change\n" +
    " from the lush grassy plains to the east. Westward you can see\n" +
    "a huge desert stretching from horizon to horizon, bounded on all\n" +
    "sides by steep cliffs.\n";

  dest_dir = ({
    NWDESERT + "rooms/desert04", "west",
    NWPLAINS + "rooms/plain27", "east",
    NWDESERT + "rooms/scrub05", "north",
    NWPLAINS + "rooms/plain29", "south",
  });

  items = ({
    "brush", "Some dry plants which can survive this harsh environment",
    "scrub brush", "Sickly-looking plant life",
    "plains", "The plains are a sharp contrast to this area",
    "desert", "The desert is huge and sparkles in the light of the sun",
    "cliffs", "Sheer rocky cliffs walling off the desert",
  });
  clone_list = ({
    1, 2, "snake", NWDESERT + "monsters/yellowsnake", 0,
  });
  ::reset(arg);
  replace_program("/room/room");
}
