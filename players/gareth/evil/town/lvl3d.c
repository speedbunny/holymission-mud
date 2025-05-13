#include "/players/gareth/define.h"
inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {

  set_light(1);
  short_desc = "washroom";
  long_desc = 
   "It's quite clear that the drow consider it very important\n"+
   "to be clean, judging by this room.  Half of the room is \n"+
   "taken up by shallow basins.  Thin ropes are strung across\n"+ 
   "the ceiling. The other half of the room contains four ceramic\n"+ 
   "bathtubs. There are racks on the walls hold towels.\n";
  
  items = ({
    "basins","shallow wash basins used for washing clothes",
    "ropes","thin lines that have clothes hanging on them to dry",
    "bathtubs","bathtubs made of cermanic used for bathing",
    "racks","common rods that are used for holding towels not in use",
    "towels","wet towels hnaging on racks to dry",
     });

  dest_dir = ({
    ETOWN+"lvl4a","up",
    ETOWN+"lvl3c","north",
    ETOWN+"lvl3b","east",
     });

}
}
