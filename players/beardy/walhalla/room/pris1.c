inherit"room/room";
#include "../walhalla.h"

reset(int arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Walhalla's prison",
    long_desc="This is the entrance to Walhalla's prison. The walls are\n" +
              "cold an wet in here and you have a creepy feeling of entering\n" +
              "it. Several strange sounds are heard from the darkness and\n" +
              "some are recognized as painful shouts.\n";
    
    items=({"darkness","It's dark",
            "walls","They are wet",
            "wall","It is weg",
            "sounds","Oh what a horror "});

    property =({"no_teleport"});

    dest_dir =({ROOM + "pris2","south",
                ROOM + "hallx","north"});

    smell = "It smells like death";
  }
}
