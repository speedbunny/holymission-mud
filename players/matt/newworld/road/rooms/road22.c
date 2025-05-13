inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Mountain Road";
  long_desc =
    "    You are at a twist in the road, which curves east higher\n" +
    "up and southwest further down. A light snow falls from the\n" +
    "sky, landing on you in small flecks and instantly melting.\n" +
    "This place is so high in the mountains that the ground below\n" +
    "is nothing more than a hazy pattern of colors, and faint\n" +
    "wisps of clouds hang in the air around you.\n";

  dest_dir = ({
    NWROAD + "rooms/road23", "east",
    NWROAD + "rooms/road21", "southwest",
  });

  items = ({
    "road", "North Road takes a twist here",
    "snow", "Snowflakes fall around you and cover the landscape",
    "ground", "The ground is far, far below you",
    "clouds", "Faint hints of clouds hang in the air here",
    "wisps", "Misty clouds",
  });
  replace_program("/room/room");
}
