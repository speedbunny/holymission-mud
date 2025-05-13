 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

   set_light(0);
short_desc="Cave of the Serpent";
    long_desc= break_string(
              "You are in a dark tunnel leading even deeper into the mountain. You feel the "+
              "darkness surround you. The walls appear to be made of smooth, grey stone.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
          "floor","The floor is starting to smooth out."});

dest_dir=({CPATH+"c1","south",CPATH+"c3","north"});
}
