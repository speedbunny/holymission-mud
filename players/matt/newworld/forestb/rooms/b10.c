inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Bright Forest";
  long_desc =
    "    This section of the forest is a bit dimmer than most,\n" +
    "as the branches overhead intertwine more thickly and allow\n" +
    "less sunlight through. The ground here is a bit muddy, and\n" +
    "your feet sink in slightly as you shift your weight.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b06", "west",
    NWFORESTB + "rooms/b09", "north",
    NWFORESTB + "rooms/b11", "south",
  });

  items = ({
    "forest", "You are close to the heart of the forest",
    "branches", "A dense tangle of branches",
    "sunlight", "There is less light here than in other areas",
    "ground", "The ground is wet and a bit muddy",
    "mud", "A thin layer of mud covering the ground here",
  });
  replace_program("/room/room");
}
