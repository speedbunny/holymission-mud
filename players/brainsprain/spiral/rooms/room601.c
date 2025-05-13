inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Flat place";
  long_desc =
"The floor has come to a flat place.  The smell of orc is strong here "+
"and is very pungent.  A skeleton lies in a corner of the room.  The "+
"western wall is coated in a thin paste of water and dirt.\n";
   set_light(0);
    dest_dir = ({
    sr+"/room511","north",
    sr+"/room602","south",
  });
  items =({
    "skeleton",
    "the skeleton of a long dead adventurer",
     "floor","A flat floor",
     "wall","It is coated by a thin paste of water and dirt",
     "water","It is pasted to the wall",
     "dirt","It is pasted to the wall",
  });
  ::reset(arg);
    replace_program("room/room");
}
