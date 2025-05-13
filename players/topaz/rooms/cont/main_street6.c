inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Eastern end of Main Street";
    long_desc="This is towards the eastern end of Main Street.\n" +
              "To the north you notice the entry to an old building.\n";

    dest_dir=({CONT + "main_street5","west",
               CONT + "main_street7","east",
                GUILDS + "adv_guild","north",
    });
    items=({"road","A much used road",
            "street","A much used road",
            "river","It looks refreshing",
            "entry","It enters the old building",
            "building","It looks important and well used",
            "old building","It looks important and well used",
    });
    set_light(1);
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
    MP("diving into the river#players/topaz/rooms/river/river12");
    return 1;
  }
  else {
    write("Enter what?\n");
    return 1;
  }
}
