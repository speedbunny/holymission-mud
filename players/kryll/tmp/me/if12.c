inherit "/room/room";

#include "/players/kryll/rooms/room_defs.h"

void reset(int arg) {
  set_light(0);
  short_Desc = "A dark part of the forest";
  long_desc =
    "This is the back corner of the Ilkin Forest. You are surrounded "+
    "by trees and bushes that seem to have a mind and sense of their "+
    "own. You barely make out a trail leading west amid some bushes. "+
    "Beware of what lurks around you.\n";

  items = ({
    "forest","The dark part of the forest is tainted with evil",
    "trees","You feel like they are watching you",
    "bushes","Thorny bushes prevent a lot of your movement",
    "trail","A trail leading west. Just go that direction",
  });

  smell = "Is that rotting leaves you smell?\n";
  dest_dir = ({
    ILKIN_FOREST + "if08", "south",
    ILKIN_FOREST + "if10", "east",
  });

  hidden_dir = ({
    ILKIN_FOREST + "if06", "west",
  });

  ::reset(arg);
  replace_program("/room/room");
}

