inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Standard Room";
    long_desc="This is a standard room.\n";

    dest_dir=({CONT + "main_street3","north",
               CONT + "post_office","west",
               CONT + "town_hall","east",
    });
    items=({"room","A standard room",
    });
    set_light(1);
return 1;
  }
}
