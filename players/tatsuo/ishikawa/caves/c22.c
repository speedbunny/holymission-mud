 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

   set_light(0);
short_desc="Cave of the Serpent";
    long_desc= break_string(
    "You have entered an oppressivly hot and dark tunnel. You can smell "+
     "the fear pouring from within. The tunnel slopes downward as you "+
    "go further in.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
            "floor","The floor is rough and covered with little holes",
            "holes","The holes are very shallow and only appear to threaten unwary ankles"});

dest_dir=({CPATH+"t21","south",CPATH+"t23","northeast",CPATH+"t27","northwest",});
}
