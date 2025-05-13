inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Moutnain Road";
  long_desc =
    "    You stand on North Road just above the foot of the\n" +
    "mountains. The wind is surprisingly strong and cold even\n" +
    "here; you shiver as you look upwards and see a frosty white\n" +
    "glaze over the rocky landscape above you. The road itself\n" +
    "continues south towards the highlands and north further up\n" +
    "into the mountains.\n";

  dest_dir = ({
    NWROAD + "rooms/road17", "north",
    NWROAD + "rooms/road15", "south",
  });

  items = ({
    "mountains", "Capped with snow, the mountains are rough and rocky",
    "road", "The road is rocky and drastically sloped here",
    "highlands", "Green hills spread out far below you",
  });
  replace_program("/room/room");
}
