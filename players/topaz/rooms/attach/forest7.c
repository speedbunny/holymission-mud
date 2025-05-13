inherit "room/room";

#include "/players/topaz/defs.h"

int found;
reset(arg) {
  found=0;
  if(!arg) {
    short_desc="In a bush";
    long_desc="There is a huge space inside this bush!\n" +
              "It seems to be some sort of play area.\n" +
              "There must be something else in the bush, because\n" +
              "you hear rustling noises coming from it.\n";

    dest_dir=({ATTACH + "forest4","north",
    });
    items=({"bush","Something seems to be rustling the bush",
            "bushes","Something seems to be rustling them",
    });
    set_light(1);
return 1;
  }
}
init(){
  ::init();

    add_action("_search","search");
}
_search(str) {
    object bearcub;
    if(!id(str)) {
    write("Search what?\n");
    return 1;
    }
    if((str=="bush"||str=="bushes")  && !found) {
    write("You search the bushes and find out what was making the\n" +
          "rustling noises.  A small bear cub!\n");
    say(this_player()->query_name() + " searches the bushes and a small bear" +
          "cub comes out!");
move_object(bearcub=clone_object(MNST + "attach/bearcub"),this_object());
    found=1;
    return 1;
    }
}
