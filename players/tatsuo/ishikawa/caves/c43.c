 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

   set_light(0);
short_desc="Cave of the Serpent";
    long_desc= break_string(
    "This room is so disgusting you feel begin to feel sick. "+
    "There are bones and trash lying around the floor. "+
   "You can see blood stains on the walls and floor. The smell is coming "+
    "from the north.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
   "floor","The floor is filthy covered with bones and scum.",
  "bones","Past meals for some creature no doubt.",
           "bone","That might be yours if your not careful"});

dest_dir=({CPATH+"c42","north",CPATH+"c41","east"});
}
