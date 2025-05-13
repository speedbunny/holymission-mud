inherit "/room/room";

#include "/players/kryll/include/room_defs.h"

void reset(int arg) {
  set_light(0);
  short_Desc = "The dark clearing in the Ilkin Forest";
  long_desc =
    "This back corner of the clearing radiates somewhat strong evil. "+
    "Beware of what lurks around you. There is also a strange symbol "+
    "etched into the ground here.\n";

  items = ({
    "forest","The dark part of the forest is tainted with evil",
    "clearing","A small clearing in the forest, with but a few trees "+
               "to prevent movement around this dismal place",
    "trees","There are few trees in this clearing",
    "symbol","The symbol looks like this:\n"+
             "                       \n"+
             "             /|        \n"+
             "            / |        \n"+
             "           /  | /|     \n"+
             "           ___|/ |     \n"+
             "              |  |     \n"+
             "              |  |     \n"+
             "                       \n",
    "ground","It is all dirt",
  });

  smell = "Is that rotting leaves you smell?\n";
  dest_dir = ({
    ILKIN_FOREST + "if02", "south",
    ILKIN_FOREST + "if03", "east",
  });

  clone_list = ({
    1,6,"quickling",MONSTER+"quickling",0,
    2,1,"demon",MONSTER+"demons/little_demon",0,
  });

  ::reset(arg);
  replace_program("/room/room");
}

