inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int rnd;

void reset(int arg) {
  
  short_desc = "Town road";
  long_desc =
    "The sounds of rauchous laughter comes from behind the wall of the "+
    "building to the east.  A cemetary is barely visible over the western wall "+
    "which is covered in an eerie black ivy.  The road continues north-south.\n";
  set_light(1);
  dest_dir = ({
    br+"/tr-9","north",
    br+"/tr-11","south",
  });
  items = ({
    "ivy",
    "A rare form of ivy called deaths shade",
    "road",
    "The main road in Towpath",
    "towpath",
    "The town you are in",
    "building",
    "The bar",
    "wall",
    "The outer wall of the bar",
    "cemetary",
    "The graves of long dead soldiers and citizens",
  });
  rnd = random(3);
  clone_list = ({ 1, rnd, "peas",
		  bm+"/peas", 0 });
  ::reset(arg);
  replace_program("room/room");
}
