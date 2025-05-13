inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "The east - west section of Rich Men's Road";
  long_desc =
    "You walk on the east - west section of Rich Men's Road. To "+
    "the east The road turns south, to the west it turns north "+
    "again. South you look at the blind wall of a builing.\n";

  dest_dir = ({
    HM_VILLAGE + "road2", "east",
    HM_VILLAGE + "road4", "west",
  });

  items = ({
    "rich men's road","The road through the richer part of the village",
    "road","A well paved road of red bricks",
    "bricks","Red bricks form the roadsurface",
    "wall","The wooden wall of a building. A sign on it says: "+
      "Pub entrance at the square",
    "building","A wooden building, like most buildings in this village",
  });

  ::reset(arg);
  replace_program("room/room");
}

