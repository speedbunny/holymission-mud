inherit "/room/room";

#include "actions.h"

void reset(int arg){
  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "On the river bank";
  long_desc =
    "You're on the bank of a river, where it a tributary splits off "+
    "from it. There is a slightly overgrown path leading under the "+
    "bridge to the north, and there is one leading up the bank. "+
    "There are many bushes and trees in this area, as they get plenty "+
    "of water from the river.\n";

  items = ({
    "bushes","There are plenty of them",
    "trees","The trees grow well in this well-watered area",
    "bridge","There is a bridge to the north allowing travellers "+
      "to cross the river",
    "tributary","A stream splits off from the river heading south",
    "bank","The bank of the river is very lush",
    "path","This path appears to lead nprth and up",
    "river","You see a big blue river which seems too deep to enter",
    "water","It looks cool and refreshing",
  });

  dest_dir = ({
    HOBBE + "under_bridge", "north",
    HOBBE + "path1", "up",
  });
}

