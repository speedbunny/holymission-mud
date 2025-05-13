 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

    set_light(1);
short_desc="Cave of the Serpent";
    long_desc= break_string(
     "You are following a path around a stalagmite. The stalagmite rises up to your "+
     "west. There is a tunnel leading off northeast. The path continues around the "+
     "stalagmite.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
            "floor","The floor is rough and covered with little holes",
    "stalagmite","It rises into the darkness.",
    "tunnel","The tunnel is dark and looks forbidding.",
            "holes","The holes are very shallow and only appear to threaten unwary ankles"});

dest_dir=({CPATH+"c6","southwest",CPATH+"c13","northeast"});
}
