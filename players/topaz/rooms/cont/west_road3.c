inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Standard Room";
    long_desc="This is a standard room.\n";

    dest_dir=({CONT + "west_road2","west",
               CONT + "west_road4","south",
               CONT + "main_street1","north",
    });
    items=({"room","A standard room",
    });
    set_light(1);
return 1;
  }
}
