 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

   set_light(0);
short_desc="Cave of the Serpent";
    long_desc= break_string(
    "The smell of decay is so badnow that you are almost "+
    "sick. The smell comes from the west. The tunnel is littered "+
    "with debris and rotted clothes.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
            "floor","The floor is rough and covered with little holes",
   "debris","It appears to be the remains of explorers who were very unlucky.",
    "clothes","Nothing you would want to wear."});

dest_dir=({CPATH+"c43","west",CPATH+"c40","south"});
}
