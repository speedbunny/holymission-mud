inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Bend";
  long_desc =
    "    The road bends here, running directly north and southwest.\n" +
    "You stand just outside of the dark forest, at the southern end\n" +
    "of the plains which lie on either side of the road. The\n" +
    "mountains are clearly visible from here, and you can just make\n" +
    "out a tall structure on the highest peak. The wind blows rather\n" +
    "strongly, ruffling your hair.\n";

  dest_dir = ({
    NWROAD + "rooms/road07", "north",
    NWROAD + "rooms/road05", "southwest",
    NWPLAINS + "rooms/plain01", "east",
    NWPLAINS + "rooms/plain02", "west",
  });

  items = ({
    "plains", "Grass-covered plains stretching before you",
    "road", "The road looks worn here",
    "mountains", "Huge icy peaks towering over the landscape",
    "forest", "A dark forest to your south",
    "structure", "You can barely see it",
  });
  replace_program("/room/room");
}

