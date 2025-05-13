inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="The Allport Mages Guild";
    long_desc="This is where the mages guild on this continent will be.\n";

    dest_dir=({CONT + "magic_shop","west",
    });
    items=({"room","A standard room",
    });
    set_light(1);
return 1;
  }
}
