inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Mountain Road";
  long_desc =
    "    The road continues to twist and turn due to the uneven\n" +
    "nature of the landscape; it rises higher to the northwest,\n" +
    "and dips back down to the northeast. The snow here covers\n" +
    "the land in a rather thick layer, making travelling a bit\n" +
    "difficult. The frigid wind comes and goes in sudden gusts,\n" +
    "chilling you to the bone.\n" +
    "    You can see the top of a black tower far above you.\n";

  dest_dir = ({
    NWROAD + "rooms/road20", "northwest",
    NWROAD + "rooms/road18", "northeast",
  });

  items = ({
    "road", "You can barely see it through the snow",
    "snow", "The snow is up to your ankles here",
    "tower", "A tall black tower; only the very top is visible",
  });
  replace_program("/room/room");
}


