inherit "/room/room";

#include "/players/kryll/include/room_defs.h"

void reset(int arg) {
  set_light(0);
  short_Desc = "The dark clearing in the Ilkin Forest";
  long_desc =
    "This clearing radiates a strong evil. It is as if it were created "+
    "to perform some evil summoning magic. Beware of what lurks "+
    "around you.\n";

  items = ({
    "forest","The dark part of the forest is tainted with evil",
    "clearing","A small clearing in the forest, with but a few trees "+
               "to prevent movement around this dismal place",
    "trees","There are only a few in this clearing",
  });

  smell = "Is that rotting leaves you smell?\n";
  dest_dir = ({
    ILKIN_FOREST + "if06", "south",
    ILKIN_FOREST + "if03", "west",
  });

  clone_list = ({
    1,2,"quickling",MONSTER+"quickling",0,
    2,1,"imp",MONSTER+"demons/imp",0,
  });

  ::reset(arg);
  replace_program("/room/room");
}

