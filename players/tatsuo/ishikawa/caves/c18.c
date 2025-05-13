 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

    set_light(1);
short_desc="Cave of the Serpent";
    long_desc= break_string(
   "You are following a path around a huge stalagmite. You can see a tunnel "+
    "leading into darkness heading northwest. The path continues on around the  "+
   "stalagmite.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
            "floor","The floor is rough and covered with little holes",
    "tunnel","The tunnel looks forbidding and it is very dark.",
    "stalagmite","It rises up into the darkness.",
            "holes","The holes are very shallow and only appear to threaten unwary ankles"});

dest_dir=({CPATH+"c9","south",CPATH+"c19","northwest"});
}
