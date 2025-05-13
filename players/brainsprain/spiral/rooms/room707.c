inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Corridor of statues";
  long_desc =
"This corridor is lined with stone statues of orcs.  They stand in "+
"various battle positions.  At the eastern end of the hallway a set of "+
"double doors.  The overpowering scent of kerosene comes from the "+
"northeast.\n";
   set_light(0);
    dest_dir = ({
    sr+"/room708","east",
    sr+"/room706","northwest",
  });
  items =({
    "statues",
    "statues of battling orcs that guard this hall",
    "doors",
    "a set of iron studded double doors",
  });
clone_list = ({ 
       1, 3, "monster", sm+"/orc_guard.c", 0,
        });
  ::reset(arg);
    replace_program("room/room");
}
