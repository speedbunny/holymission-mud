 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

   set_light(0);
short_desc="Cave of the Serpent";
    long_desc= break_string(
               "You are in a very dark tunnel. The darkness seems to be a living entity "+
               "smothering you. There is a hole leading down further into the mountain.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
            "floor","The floor is rough and covered with little holes",
            "hole","The hole leads further down into the darkness. It looks like you could enter."});

dest_dir=({CPATH+"c4","down",CPATH+"c2","south"});
}
