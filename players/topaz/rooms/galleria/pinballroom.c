inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Pinball Room";
    long_desc="This is a room specifically designed to play pinball in.\n" +
              "You should try the pinball machine out.  :)\n";

    dest_dir=({GALL + "hallway2_1.c","south",
    });
    items=({"room","It's made only for playing pinball",
    });
    set_light(1);
    move_object(clone_object(OBJS + "galleria/pinball"),TO);
return 1;
  }
}
