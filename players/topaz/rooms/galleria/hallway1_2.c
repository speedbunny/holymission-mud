inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Galleria Hallway";
    long_desc="The hallway is under construction.\n";

    dest_dir=({GALL + "hallway1_1","south",
    });
    items=({"hallway","It's not completely built yet",
    });
    set_light(1);
return 1;
  }
}
