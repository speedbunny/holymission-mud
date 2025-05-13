inherit"room/room";
#include "../walhalla.h"
#include "../prison.h"

int i;

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Hall of Justice",
    long_desc="This is the Hall of Justice. Left and right there are seats\n" +
              "with lots of monster and humans on trying to follow and listen\n" + 
              "to the showdown.\n";
    
    items=({"monsters","Various once, perhaps you have seen the one or the other",
            "human","A normal human"});

    property =({"teleport"});

    dest_dir =({ROOM + "hall2","south",
                ROOM + "hall5","east"});

    smell = "Nothing special";
    for(i=0;i<=5;i++) 
     CM("visitor");

   if(random(GUARD_IN_HALL)==0)
     CM("cguard");
  }
}
