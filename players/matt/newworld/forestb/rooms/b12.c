inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Bright Forest";
  long_desc =
    "    You stand in the lush Eastern Forest, surrounded by dark\n" +
    "ancient trees and the busy scurryings and callings of small\n" +
    "woodland creatures. It seems as though mankind has not yet\n" +
    "touched this place.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b07", "west",
    NWFORESTB + "rooms/b11", "north",
    NWFORESTB + "rooms/b15", "southeast",
  });

  items = ({
    "forest", "A brightly-lit forest",
    "trees", "Dark trees standing tall above you",
    "creatures", "You see animals like squirrels, birds, and chipmunks",
    "squirrels", "Small squirrels gathering nuts for the winter",
    "birds", "Brightly-colored birds singing happily",
    "chipmunks", "Small animals scurrying up and down their trees",
  });
  replace_program("/room/room");
}
