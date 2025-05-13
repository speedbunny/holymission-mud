 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

   set_light(0);
short_desc="Cave of the Serpent";
    long_desc= break_string(
              "You are in a dark tunnel, you can feel heat coming from the north. A hole "+
          "leading back to the entrance of the cave is above you. The darkness"+
             "alive.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
            "floor","The floor is rough and covered with little holes",
            "holes","The holes are very shallow and only appear to threaten unwary ankles"});

dest_dir=({CPATH+"c3","up",CPATH+"c5","north"});
}
