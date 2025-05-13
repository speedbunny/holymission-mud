inherit"room/room";
#include "../walhalla.h"

int i;

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(0);
    short_desc="Catacombs",
    long_desc="You are in the ancient Catacombs. The walls look very\n" +
              "strange and old. Everything is covered with dust and\n" +
              "blood. Strange noise is heard too. Oh, you feel ugly\n" +
              "down here.\n";

    items=({"walls","They seem to be very old",
            "dust","It's normal dust"});

    property =({"no_teleport"});

    dest_dir =({ROOM + "cat2","southwest",
                ROOM + "cat4","east"});

    smell = "Oh god ! It smells ugly in here";

    for(i=0;i<=6;i++)
      CM("catamon");

  }
}
