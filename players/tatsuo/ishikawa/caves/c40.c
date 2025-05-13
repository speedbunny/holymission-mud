 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

   set_light(0);
short_desc="Cave of the Serpent";
    long_desc= break_string(
     "You are in a dark tunnel. The tunnel curves here and "+
     "heads north. The tunnel smells of decay and death. The "+
     "grooves are deeper here.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
            "floor","The floor is covered in deep grooves.",
    "grooves","Do you really want to know what caused those grooves?"});

dest_dir=({CPATH+"c39","east",CPATH+"c41","north"});
}
