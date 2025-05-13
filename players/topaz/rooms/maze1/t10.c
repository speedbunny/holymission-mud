inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(!arg) {
    short_desc="A very dark room";
    long_desc="A very dark room.\n";

    hidden_dir=({MAZE1 + "t12","south",
                MAZE1 + "t13","west",
                MAZE1 + "t8","north",
    });
    set_light(-1000);
return 1;
  }
}

init() {
    ::init();
    add_action("_move","east");
}

_move() {
    write("You cannot go that way.\n");
    return 1;
}
