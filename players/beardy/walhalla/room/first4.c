inherit"room/room";
#include "../walhalla.h"

int i;

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="First floor",
    long_desc="This is the first floor of Walhalla. You are in a small\n" +
              "ugly gangway leading to the north. Hope you'll get out \n" +
              "of here sometimes.\n";
    
    items=({"gangways","Oh ! It's really ugly -  trust me..."});

    property =({"no_teleport"});

    dest_dir =({ROOM + "first5","north",
                ROOM + "first1","south"});

    smell = "It smells awful now";

    for(i=1;i<=3;i++)
     CM("firstmon");

  }
}
