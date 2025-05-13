inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Desert Border";
  long_desc =
    "    Scrub brush is abundant here, a drastic change from the\n" +
    "lush grassy plains to the east. Westward you can see miles\n" +
    "of desert stretching from horizon to horizon, bounded on all\n" +
    "sides by high cliffs that also extend to the east and south.\n";

  dest_dir = ({
    NWDESERT + "rooms/desert01", "west",
    NWPLAINS + "rooms/plain25", "north",
  });

  items = ({
    "brush", "Some dry plants which can survive this harsh environment",
    "scrub brush", "Sickly-looking plant life",
    "plains", "The plains are a sharp contrast to this area",
    "desert", "The desert is huge and sparkles in the light of the sun",
    "cliffs", "Sheer rocky cliffs walling off the desert",
  });
}

init() {
  ::init();
  add_action("no_way", "east");
  add_action("no_way", "south");
}

no_way() {
  write("The cliffs block your way.\n");
  return 1;
}
