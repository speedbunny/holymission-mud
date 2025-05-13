inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(!arg) {
    short_desc="A very dark room";
    long_desc="A very dark room.\n";

    hidden_dir=({MAZE1 + "t9","north",
                MAZE1 + "t4","east",
                MAZE1 + "t8","west",
    });
    set_light(-1000);
return 1;
  }
}

init() {
    ::init();
    add_action("_move","south");
}

_move() {
    write("You cannot go that way.\n");
    return 1;
}
