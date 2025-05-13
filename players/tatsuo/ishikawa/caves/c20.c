 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

    set_light(0);
short_desc="Cave of the Serpent";
    long_desc= break_string(
     "You have entered a room somewhat larger than the rest of "+
     "the tunnels. There is a hole leading down. You feel your "+
     "legs weaken from the cold and fear. The room is square shaped "+
     "and is composed of the same smooth rock as the tunnel.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
          "hole","The hole is dark and steep. If you climb down you probably won't get back!",
            "floor","The floor is rough and covered with little holes",
            "holes","The holes are very shallow and only appear to threaten unwary ankles"});
dest_dir=({CPATH+"t50","down",CPATH+"t31","south"});

property =({"no_teleport"});
}
