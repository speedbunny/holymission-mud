inherit "/room/room";

#include "/players/kryll/rooms/room_defs.h"

void reset(int arg) {
  set_light(0);
  short_Desc = "The dark clearing in the Ilkin Forest";
  long_desc =
    "This clearing radiates a strong evil. It is as if it were created "+
    "to perform some evil summoning magic. You barely notice are "+
    "rather unused trail through some bushes to the east.\n";

  items = ({
    "forest","The dark part of the forest is tainted with evil",
    "clearing","A small clearing in the forest, with but a few trees "+
               "to prevent movement around this dismal place",
    "trees","There are only a few in this clearing",
    "trail","A trail leading east, meaning you can go that way",
    "bushes","A lot of bushes surround this clearing",
  });

  smell = "Is that rotting leaves you smell?\n";
  dest_dir = ({
    ILKIN_FOREST + "if05", "north",
    ILKIN_FOREST + "if04", "west",
  });

  hidden_dir = ({
    ILKIN_FOREST + "if07", "east",
  });

  clone_list = ({
    1,1,"quickling",MONSTER+"quickling",0,
    2,2,"imp",MONSTER+"demons/imp",0,
  });

  ::reset(arg);
  replace_program("/room/room");
}

