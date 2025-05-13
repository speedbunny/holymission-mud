inherit"room/room";
#include "../walhalla.h"

reset(int arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Court Yard",
    long_desc="This is Walhalla's court Yard. You are in the judge's room.\n" +
              "Here the penalty is set for your illegal killing and you\n" +
              "misbehavior.\n";
    
    property =({"no_teleport","no_hide"});

    dest_dir =({ROOM + "hall3","east"});

     CM("odin");
     CM("thor");
     CM("cguard");
  }
}
