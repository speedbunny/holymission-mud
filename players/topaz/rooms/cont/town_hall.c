inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Standard Room";
    long_desc="This is a standard room.\n";

    dest_dir=({CONT + "bank","east",
               CONT + "main_street4","north",
               CONT + "sheriff","west",
               CONT + "town_hall2","down",
               CONT + "clerks_room","south",
    });
    items=({"room","A standard room",
    });
    set_light(1);
return 1;
  }
}
