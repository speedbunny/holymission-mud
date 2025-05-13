inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Main Street";
    long_desc="You are on Main Street.\n" +
              "The river passes under the road west of here.\n" +
              "The Allport branch of the 'Brokers Assoc.' is to the south.\n";

    dest_dir=({CONT + "main_street4","west",
               CONT + "main_street6","east",
                CONT + "bank","south",
    });
    items=({"road","A much used road",
            "street","A much used road",
            "river","It looks refreshing",
            "bridge","A tiny little bridge, just to cross the river",
            "bank","That's where players can keep their money",
             "broker","That's where players can keep their money",
    });
    set_light(1);
return 1;
  }
}

init() {
  ::init();

    add_action("_enter","enter");
    add_action("_west","west");
}

_enter(str) {
  if(str=="river" || str=="the river") {
    write("You dive into the river.\n");
    MP("diving into the river#players/topaz/rooms/river/river11");
    return 1;
  }
  else {
    write("Enter what?\n");
    return 1;
  }
}

_west(str) {
  if(!str) {
    write("You cross over a little bridge and go west.\n");
    MP("east#players/topaz/rooms/cont/main_street4");
    return 1;
  }
  else {
    return 1;
  }
}
