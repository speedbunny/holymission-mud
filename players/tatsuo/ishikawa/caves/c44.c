 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

    set_light(1);
short_desc="Cave of the Serpent";
    long_desc= break_string(
        "You are standing in an immense underground cavern. There is a huge stalagmite "+
        "rising up from the ground to your west and east. You can see a reddish "+
        "glow coming from the north. You are beginning to get warmer.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
           "stalagmite","There is a huge stalagmite rising into the darkness to the west.",
      "floor","The floor is smooth and unblemished."});

dest_dir=({CPATH+"c7","south",CPATH+"c8","southwest",CPATH+"c6","southeast"});
}
