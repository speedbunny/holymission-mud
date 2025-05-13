inherit "room/room";
#include "/players/baalthasar/shadows/path.h"

  reset(arg) {
 if(arg) return;

set_light(1);
  short_desc = "Road into the mist";
  long_desc = 
"     You feel very disoriented as you wander deeper into the mist \n"+
"and the chilling cold.  Beneath your feet is a worn and old dusty \n"+
"path which appears to be little used now with spurts of grass here \n"+
"and there.  The mist thickens in all directions around you except \n"+
"east.  You can see the road runs east and west. \n";

dest_dir = ({
PATH + "/mroad2", "west",
PATH + "/lost", "north",
PATH + "/entry", "east",
PATH + "/lost2", "south"
});

items = ({
  "mist", "The dark grey mist flows in all directions except for a \n"+
  "clearing to the east",
  "path", "The road runs east and west, the only safe guide through the mist",
  "road", "The road runs east and west, the only safe guide through the mist",
  "grass", "Patches of dying grass are scattered along the road"
});

  }
