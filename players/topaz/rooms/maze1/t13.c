inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(!arg) {
    short_desc="A very dark room";
    long_desc="A very dark room.\n";

    hidden_dir=({MAZE1 + "t10","east",
    });
    set_light(-1000);
return 1;
  }
}

init() {
    ::init();
    add_action("_move","west");
    add_action("_move","north");
    add_action("_move","south");
}

_move() {
    write("You cannot go that way.\n");
    return 1;
}
