inherit "room/room";

#include "/players/topaz/defs.h"

_jump(str) {
  if(!str) {
    write("You jump toward the post office...\n\n\n\n" +
          "You made it!\n" +
          "You look up and amazingly the hole in the roof magically\n" +
          "seals itself up!\n");
    MP("jumping toward the post office#room/post");
    return 1;
  }
  write("You don't think you can do that.\n");
  return 1;
}
reset(arg) {
  if(!arg) {
    short_desc="A big oak tree";
    long_desc="You are in the big oak tree.\n" +
              "It is nice up here.  You can see the meadow you were\n" +
              "just in.  You can also see the post office from here.\n" +
              "There is a hole in the roof of the post office and you\n" +
              "think you might be able to 'jump' to the post office from\n" +
              "here.\n";

    dest_dir=({ATTACH + "meadow","down",
               "room/post","jump",
    });
    items=({"tree","It is sturdy enough to hold many people",
            "post office","You think you could 'jump' from here to it",
            "meadow","It looks peaceful from up here",
    });
    set_light(1);
    smell="The tree's leaves smell fresh and good.";
return 1;
  }
}

init() {
  ::init();

    add_action("_jump","jump");
}
