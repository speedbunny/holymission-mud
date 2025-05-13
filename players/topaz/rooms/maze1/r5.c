inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="A maze";
    long_desc="This magical maze is confusing, but you feel\n" +
              "that you are ALMOST there!!\n";

    dest_dir=({MAZE1 + "r1","south",
               MAZE1 + "s11","north",
               MAZE1 + "r1","west",
               MAZE1 + "r1","east",
    });
    items=({"maze","This maze is wacko",
    });
    set_light(1);
return 1;
  }
}

init() {
  ::init();

    add_action("_north","north");
    add_action("_north","n");
}

_north(str) {
  if(!str) {
    write("You made it!\n");
    write("Well......you almost made it.\n" +
          "It appears that you've just made it to another section\n" +
          "of this magical maze.\n");
    MP("north#players/topaz/rooms/maze1/s11");
    return 1;
  }
  return 1;
}
