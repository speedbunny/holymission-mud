inherit"room/room";
#include "../walhalla.h"

reset(int arg)
{ ::reset(arg);
  if(!arg)
  { int i;
    set_light(1);
    short_desc="Hall of Justice",
    long_desc="You are in front of the court. The feeling is not very well\n" +
              "have this moment. The solicitor has finished his speach\ and the\n" + 
              "guards are going to get you.\n";
    
    items=({"monsters","Various once, perhaps you have seen the one or the other",
            "human","A normal human"});

    property =({"teleport"});

    dest_dir =({ROOM + "hall2","east",
                ROOM + "hall6","west",
                ROOM + "hall4","north",
                ROOM + "hall0","south"});

    smell = "Nothing special";

    for(i=1;i<=1;i++)
      CM("cguard");
  }
}
