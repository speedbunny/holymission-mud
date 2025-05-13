inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Desert Border";
  long_desc =
    "    Scraggly brush is abundant here, much different from the\n" +
    "green grassy plains to the east. Westward you can see a vast\n" +
    "desert stretching from horizon to horizon, surrounded on all\n" +
    "sides by high cliffs, which extend directly north as well.\n";

  dest_dir = ({
    NWDESERT + "rooms/desert05", "west",
    NWPLAINS + "rooms/plain28", "east",
    NWDESERT + "rooms/scrub04", "south",
  });

  items = ({
    "brush", "Some dry plants which can survive this harsh environment",
    "plains", "The plains are a sharp contrast to this area",
    "desert", "The desert is huge and sparkles in the light of the sun",
    "cliffs", "Sheer rocky cliffs walling off the desert",
  });
}

init() {
  ::init();
  add_action("no_way", "north");
}

no_way() {
  write("The cliffs block your way.\n");
  return 1;
}
