inherit "room/room";
#include "/players/tatsuo/def.h"
#define TEST_MON ({"t20","t16","t8","t4"})
#include "/players/tatsuo/break_string.h"

object ob, ob1;
reset(arg)
{
    if(arg) return;

    set_light(0);
    short_desc="Cave of the Serpent";
    long_desc= break_string(
      "The tunnel seems to end here. "+
	    "A small stone altar stained with blood is set against the wall "+
	    "to greet visitors.  The walls appear to be solid and unmovable.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
      "floor","The floor is rough and covered with little holes",
	     "altar","Hmm, an altar with chains on it? strange?",
	     "chains","Maybe used to hold someone to the altar. Looks to gruesome to mess with",
	    "wall","Smooth, grey granite walls",
});

dest_dir=({CPATH+"t19","east"});
if(!ob){
MO(CO(MAN+"guardian"),TO);
  
}
}
