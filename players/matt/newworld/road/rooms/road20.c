inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Mountain Road";
  long_desc =
    "    It is snowing here. White flakes blow around your head,\n" +
    "prey to the icy wind wailing through cracks in the rock of\n" +
    "the mountain. The road is very rough and difficult to climb,\n" +
    "slick with snow and ice; you can move upward to the north,\n" +
    "or downward to your southeast.\n" +
    "    In the distance above you, a black tower is silhouetted\n" +
    "against the storm.\n";

  dest_dir = ({
    NWROAD + "rooms/road21", "north",
    NWROAD + "rooms/road19", "southeast",
  });
  
  items = ({
    "snow", "Flakes of white snow whirl around you",
    "road", "You can barely see the road for the storm",
    "mountain", "It's the same mountain",
    "tower", "The top half of a black tower far above you",
  });
  replace_program("/room/room");
}
