inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Standard Room";
    long_desc="This is a standard room.\n";

    dest_dir=({CONT + "town_hall","north",
    });
    items=({"room","A standard room",
    });
    set_light(1);
    smell="You smell the fresh water of the river.";
return 1;
  }
}

init() {
  ::init();

    add_action("_enter","enter");
}

_enter(str) {
  if(str=="river" || str=="the river") {
    write("You dive into the river.\n");
    MP("diving into the river#players/topaz/rooms/river/river19");
    return 1;
  }
  else {
    write("Enter what?\n");
  return 1;
}
}
