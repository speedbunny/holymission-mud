inherit "room/room";
#include "../walhalla.h"

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Stairhouse",
    long_desc="You have reached the top of the stairhouse.\n" +
              "Lots of noise is hear from north, perhaps some\n" +
              "guys are having a party.\n";

    items=({"stairs","What huge ones !",
            "wind","HUI.... It's gone..."});


    dest_dir =({ROOM+"up3","southwestdown",
                ROOM+"party","north"});

    smell = "It smells very unnatural in here.";

   CO("psign");
  }
}
