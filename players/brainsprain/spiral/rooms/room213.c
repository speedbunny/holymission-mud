inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A rockslide";
  long_desc =
"Rubble lies along the sides of this room and the ceiling rises up several "+
"stories.  The way to the northeast is barely passable.  Several boulders "+
"still rock precariously from ledges high along the wall.\n";
  set_light(0);
  dest_dir = ({
    sr+"/room212","west",
    sr+"/room214","northeast",
  });
 items = ({
    "rubble",
    "Rocks of varying sizes that used to be part of the ceiling",
    "boulders",
    "The boulders sit on ledges and even the slightest breeze could cause them\n"+
    "to fall",
    "ceiling",
    "It seems that the ceiling has been blasted with some explosive",
  });
	::reset(arg);
    	replace_program("room/room");
}

