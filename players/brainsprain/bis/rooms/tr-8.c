inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int rnd;

void reset(int arg) {
  
  short_desc = "Town road";
  long_desc =
    "The smell of alcohol hangs in the air.  To the south is a decrepit "+
    "building.  The wall appears to be composed of a loose pile of rocks "+
    "and lumber.  The door is little more than a hole in the wall. A "+
    "drunk man sits against the wall.\n";
  set_light(1);
  items = ({
    "pile",
    "A pile of rocks and lumber that form the wall of the tavern",
    "walls",
    "They are poorly constructed",
    "rocks",
    "They are loosely piled to form the wall",
    "lumber",
    "It is loosely piled to form the wall",
    "building",
    "An old tavern",
    "door",
    "A hole in the wall of the southern building",
    "man",
    "An old man who seems to fade into the background",
  });
  dest_dir = ({
    br+"/tr-7","east",
    br+"/tr-9","west",
    br+"/bar","south",
  });
  rnd = random(3);
  clone_list = ({ 1, rnd, "orc",
		  bm+"/peas", 0 });
  ::reset(arg);
  replace_program("room/room");
}
