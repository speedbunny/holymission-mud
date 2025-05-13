inherit "/room/room";

#include "actions.h"

void reset(int arg){
  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "On a path";
  long_desc =
    "You're wandering on a path that leads to a slow "+
    "meandering river. Bushes line both sides of the path, making this "+
    "a pleasant, scenic journey. There are some large stones lying on "+
    "the ground. There is also a path between the bushes leading "+
    "down the bank toward the river.\n";

  items = ({
    "stones","Some heavy grey stones",
    "ground","You see some heavy stones lying in the grass",
    "grass","The fresh grass looks beautiful",
    "sky","You see the blue sky",
    "bushes","They line the path",
    "path","This path appears to lead south",
    "river","You see a big blue river which seems too deep to enter",
    "water","It looks cool and refreshing"
  });

  dest_dir = ({
    "/room/forest/wild1", "north",
    HOBBE + "path2", "south"
    HOBBE + "down_path", "down"
  });
}

