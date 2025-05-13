 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

   set_light(0);
short_desc="Cave of the Serpent";
    long_desc= break_string(
    "This is a branch of the tunnel it is dark and the air "+
    "is stale. You can see the smooth walls vanish into the "+
    "darkness ahead.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
            "floor","The floor is rough and covered with little holes",
            "holes","The holes are very shallow and only appear to threaten unwary ankles"});

dest_dir=({CPATH+"c15","south",CPATH+"c17","east"});
}
