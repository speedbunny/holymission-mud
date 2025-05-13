 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

   set_light(0);
short_desc="Cave of the Serpent";
    long_desc= break_string(
     "You are in a dark tunnel. The walls are smooth and unblemished. "+
     "The darkness seems to get thicker as you progress further down "+
    "into the tunnel.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
            "floor","The floor is rough and covered with little holes",
            "holes","The holes are very shallow and only appear to threaten unwary ankles"});

dest_dir=({CPATH+"c11","southwest",CPATH+"c12","east",CPATH+"c14","north"});
}
