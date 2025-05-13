inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(!arg) {
    short_desc="A very dark room";
    long_desc="A very dark room.\n";

    hidden_dir=({MAZE1 + "t2","south",
                MAZE1 + "t7","east",
                MAZE1 + "t6","west",
    });
    set_light(-1000);
return 1;
  }
}

init() {
    ::init();
    add_action("_move","north");
}

_move() {
    write("You cannot go that way.\n");
    return 1;
}
