inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="The Allport Fighter Guild";
    long_desc="This is where the fighter guild on this continent will be.\n";

    dest_dir=({CONT + "fight_bar","north",
    });
    items=({"room","A standard room",
    });
    set_light(1);
return 1;
  }
}
