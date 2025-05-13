inherit"room/room";
#include "../walhalla.h"

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Floor One",
    long_desc="You are in the first floor of Walhalla. You are standing\n" +
              "beside the hole of the elevator. The elevator itself returned\n" +
              "after you made a step out of it.\n";
    
    items=({"hole","Huh ! It's deep",
            "elevator","There is no more elevator"});

    property =({"no_teleport","no_sneak"});

    dest_dir =({ROOM + "floor6","hole",
                ROOM + "first2","west",
		ROOM + "first4","north"});

    smell = "It smells awful now";
  }
}
