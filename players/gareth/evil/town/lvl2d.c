#include "/players/gareth/define.h"
inherit "room/room";
object drow,guard;

reset(arg) {
  ::reset(arg);
  if(!arg) {

  set_light(1);
  short_desc = "bathroom";
  long_desc = 
   "It's quite clear that the drow consider it very important\n"+ 
   "to be clean, judging by this room.  Half of the room is taken\n"+ 
   "up by shallow basins.  Thin ropes are strung across the ceiling.\n"+ 
   "The other half of the room contains four ceramic bathtubs.\n";
  
  items = ({
    "basins","shallow wash basins used for washing clothes",
    "ropes","thin lines that have clothes hanging on them to dry",
    "bathtubs","bathtubs made of cermanic used for bathing",
     });

       MO((CO(MON+"guard")),TO);
	MO((CO(MON+"guard")),TO);

  dest_dir = ({
    ETOWN+"lvl3a","up",
    ETOWN+"lvl2c","south",
    ETOWN+"lvl2b","west",
     });

}
}
