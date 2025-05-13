 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

    set_light(0);
short_desc="Cave of the Serpent";
    long_desc= break_string(
       "You are surrounded by darkness and evil. The cave has a "+
       "sinister look to it. The walls are twisted and gouged in "+
      "some places. The walls, ceiling, and floor are all "+
       "blackened and charred.\n",65);
   property=({ "no_teleport","no_sneak"});
  items=({"walls","The walls are blackened and charred.",
           "floor","The floor is rough and gouged. There are char marks all around.",
     "hole","You cannot return through that way"});
dest_dir=({CPATH+"c22","north"});
}
