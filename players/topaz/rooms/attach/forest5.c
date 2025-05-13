inherit "room/room";

#include "/players/topaz/defs.h"

_west(str) {
  if(!str) {
    write("As you go west, your foot catches on a root and you\n" +
          "fall headfirst into a hole!\n" +
          "Luckily, you don't hurt yourself.\n");
    MP("tripping over a root west#players/topaz/rooms/maze1/r1");
    return 1;
  }
  return 1;
}
reset(arg) {
  if(!arg) {
    short_desc="A cheery forest";
    long_desc="The forest is strangely quiet here.\n" +
              "You feel a weird power coming from the west.  It doesn't\n" +
              "feel evil or anything.  Just weird.  Maybe you should\n" +
              "leave here now?\n";

    dest_dir=({ATTACH + "forest3","south",
               ATTACH + "darkroom","west",
    });
    items=({"forest","The forest is peculiar here",
            "tree","The trees to the west look strange",
            "trees","The trees to the west look strange",
    });
    set_light(1);
return 1;
  }
}

init() {
  ::init();

    add_action("_west","west");
}
