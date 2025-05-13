inherit"room/room";
#include "../walhalla.h"
#include "../prison.h"

int i;

reset(int arg)
{ ::reset(arg);
  if(!arg)
  { set_light(0);
    short_desc="Walhalla's prison",
    long_desc="You are in Walhalla's prison. It is very dark in here.\n" +
              "The walls are covered with blood spills and rotten flesh.\n" +
              "Sometimes you see a head, hanging from the ceiling, looking\n" +
              "very strange. You hear lots of strange sounds, some seem to\n" +
              "be very painful shouts.\n";
    
    items=({"head","This time there is no head",
            "heads","This time there are no heads",
            "walls","They are wet",
            "wall","It is wet",
            "flesh","Yum yum yum. It tastes good",
            "blood","Normal blood spills"});

    property =({"no_teleport","no_sneak","no_hide"});

    dest_dir =({ROOM + "pris2","west",
                ROOM + "pris21","southeast"});

    smell = "You smell nothing special";

    if(random(GUARD_RANDOM)==1)
      CM("cguard");

    for(i=1;i<=MONSTER_NUMBER;i++)
      CM("pmonster");
  }
}
