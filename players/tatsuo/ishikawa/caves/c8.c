 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

    set_light(1);
short_desc="Cave of the Serpent";
    long_desc= break_string(
    "You are in the southern end of a large underground cavern. You can feel "+
    "heat coming from the northern end of the cavern. The cave is lit by a "+
    "reddish glow that comes from the north. You can see large stalagmites and "+
   "stalagtites.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
           "stalagtites","They are immense rock formations hanging from the ceiling",
           "stalagmites","They are immense rock formations that rise from the ground"});

dest_dir=({CPATH+"c7","east",CPATH+"c10","northeast",CPATH+"c9","northwest"});
}
