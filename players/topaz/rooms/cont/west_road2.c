inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="West Road";
    long_desc="This is a standard room.\n";

    dest_dir=({CONT + "west_road1","southwest",
               CONT + "west_road3","east",
    });
    items=({"road","A dark road",
    });
    set_light(1);
return 1;
  }
}
