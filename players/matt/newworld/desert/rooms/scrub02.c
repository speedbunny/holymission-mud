inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Desert Border";
  long_desc =
    "    Dry bits of scrub brush grow sparsely here, a sharp contrast\n" +
    "to the grassy plains to the east. To the west you see miles\n" +
    "of desert open before you, surrounded by sheer cliffs.\n";

  dest_dir = ({
    NWDESERT + "rooms/desert03", "west",
    NWPLAINS + "rooms/plain25", "east",
    NWPLAINS + "rooms/plain29", "north",
    NWDESERT + "rooms/desert01", "south",
  });

  items = ({
    "brush", "Some dry plants which can survive this harsh environment",
    "scrub brush", "Sickly-looking plant life",
    "plains", "The plains to the east look lush and inviting",
    "desert", "The desert is huge and sparkles in the light of the sun",
    "cliffs", "Sheer rocky cliffs walling off the desert",
  });
  replace_program("/room/room");
}
