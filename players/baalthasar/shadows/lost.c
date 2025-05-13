inherit "room/room";
#include "/players/baalthasar/shadows/path.h"

  reset(arg) {
if(arg) return;

set_light(1);
  short_desc = "Wandering through the mist";
  long_desc =
"     You wander deeper into the mist, wondering if you'll be able \n"+
"to find your way back.  The darkness continues in all directions \n"+
"with no apparent end.  You really feel as though you should return \n"+
"to the safety of the path. \n\n";

dest_dir = ({
PATH + "/mroad", "south"
});

items = ({
  "mist", "It would be your death to wander out into the mist",
  "darkness", "It would be your death to wander out into the mist",
  "path", "You can't see the path from here, but you remember it being south"
});
}
