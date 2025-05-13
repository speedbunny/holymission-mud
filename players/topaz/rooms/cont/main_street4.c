inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Main Street";
    long_desc="This is Main Street.\n" +
              "The road crosses the river to the east of here.\n" +
              "The Allport Town Hall is south.\n";

    dest_dir=({CONT + "main_street3","west",
               CONT + "main_street5","east",
                CONT + "town_hall","south",
    });
    items=({"road","A much used road",
            "street","A much used road",
            "river","It looks refreshing",
            "bridge","A tiny little bridge, just to cross the river",
            "town hall","Many important things go on there",
            "townhall","Many important things go on there",
            "hall","Many important things go on there",
    });
    set_light(1);
return 1;
  }
}

init() {
  ::init();

    add_action("_enter","enter");
    add_action("_east","east");
}

_enter(str) {
  if(str=="river" || str=="the river") {
    write("You dive into the river.\n");
    MP("diving into the river#players/topaz/rooms/river/river10");
    return 1;
  }
  else {
    write("Enter what?\n");
    return 1;
  }
}

_east(str) {
  if(!str) {
    write("You cross over a little bridge and go east.\n");
    MP("east#players/topaz/rooms/cont/main_street5");
    return 1;
  }
  else {
    return 1;
  }
}
