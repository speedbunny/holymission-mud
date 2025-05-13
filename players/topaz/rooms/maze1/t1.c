inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(!arg) {
    short_desc="A very dark room";
    long_desc="A very dark room.\n" +
              "\n" +
              "  A sign here reads:\n" +
              "                   If you can read this, you may think\n" +
              "                   this maze is impossible.  It is possible\n" +
              "                   however.  Just keep trying.  :)\n" +
              "\n";

    hidden_dir=({MAZE1 + "t3","south",
                MAZE1 + "t2","east",
    });
    set_light(-1000);
return 1;
  }
}

init() {
    ::init();
    add_action("_move","north");
    add_action("_move","west");
}

_move() {
    write("You cannot go that way.\n");
    return 1;
}
