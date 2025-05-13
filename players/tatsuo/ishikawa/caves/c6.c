 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;
  set_light(1);
short_desc="Cave of the Serpent";
    long_desc= break_string(
   "You are in a large cavern. There is a reddish glow coming from the "+
   "northern end of the caverns. You can see immense stalagtites and stalagmites. The cavern ceiling is lost in the darkness overhead.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
           "floor","The floor of the cavern is smooth as though worn down by time",
           "stalagtites","They are immense rock formations that hang from the ceiling.",
           "stalagmites","They are immense rock formations that are built from the floor up."});

dest_dir=({CPATH+"c7","west",CPATH+"c11","northeast",CPATH+"c10","northwest"});
}
