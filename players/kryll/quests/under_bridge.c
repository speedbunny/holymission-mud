inherit "/room/room";

#include "actions.h"

void reset(int arg){
  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "Under the bridge";
  long_desc =
    "The bank under the bridge is not as lush and not as bright "+
    "either. There is a stone wall blocking any further travel "+
    "north under the bridge. The river looks dark and a little "+
    "ominous here also. There is a path heading south.\n";

  items = ({
    "bridge","There is a bridge overhead that allows travellers "+
      "to cross the river",
    "bank","The bank of the river is quite desolate here",
    "path","This path appears to lead nprth and up",
    "wall","The stone wall is in the middle of the bridge. It "+
      "doesn't seem to help support the bridge, so there must "+
      "be some other use for it",
    "river","You see a dark blue river which seems too deep to enter",
    "water","It looks dark and sinister",
  });

  dest_dir = ({
    HOBBE + "down_path", "south",
  });
}

