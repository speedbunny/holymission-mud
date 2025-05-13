inherit "/room/room";

#include "/players/kryll/rooms/room_defs.h"
#include "/players/kryll/functions/river_jump.h"

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_Desc = "A dark part of the forest";
  long_desc =
    "You are in the darker part of the Ilkin Forest. You are surrounded "+
    "by trees and bushes that seem to have a mind and sense of their "+
    "own. You hear the rush of water coming from the river to the south. "+
    "Beware of what lurks around you.\n";

  items = ({
    "forest","The dark part of the forest is tainted with evil",
    "trees","You feel like they are watching you",
    "bushes","Thorny bushes prevent a lot of your movement",
    "river","The river is flowing rapidly and it looks dark, cold, "+
            "and dangerous. You aren't sure if jumping into it would "+
            "be a very good idea, but you still wonder where it goes",
  });

  smell = "Is that rotting leaves you smell?\n";
  dest_dir = ({
    ILKIN_FOREST + "if07", "north",
    ILKIN_FOREST + "if11", "southeast",
  });

  ::reset(arg);
}

void init() {
  ::init();
  add_action("_jump","jump");
}
