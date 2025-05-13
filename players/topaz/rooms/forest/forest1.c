inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Standard Room";
    long_desc="This is a standard room.\n";

    dest_dir=({CONT + "main_street3","south",
    });
    items=({"room","A standard room",
    });
    set_light(1);
    smell="The smell of the forest is refreshing.";
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
    MP("diving into the river#players/topaz/rooms/river/river8");
    return 1;
  }
  else {
    write("Enter what?\n");
  return 1;
}
}
