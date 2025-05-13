inherit"room/room";
#include "../walhalla.h"

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(0);
    short_desc="Tunnel",
    long_desc="This is the old tunnel of Walhalla. You hear the elevator\n" +
	      "hurring up and down. It's very dirty in here.\n";
    
    items=({"dirty","Oh my god, do you want to poison yourself"});

    property =({"teleport"});

    dest_dir =({ROOM +"cat5","west",
                ROOM +"treasure","southwestdown"});

    smell = "It smells like much gold is waiting for you";
  }
}
