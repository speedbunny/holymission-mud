inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) {
  if (arg) return;

  set_light(-1);
  short_desc = "In a dark Cave";
  long_desc =
"You are in a dark cave.\n"+
"This place seems to be a den of some sort, for a very\n"+
"large creature.  Its leftover meals are lying in a pile\n"+
"to one side, as are its own droppings.\n";

    dest_dir = ({
    TFOREST + "rmR2", "west",
    });

    clone_list = 
  ({1, 1, "dragon", "/players/tamina/teds/monsters/prism_dragon", 0});

    ::reset(arg);
    replace_program("room/room");
}
