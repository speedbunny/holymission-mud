inherit "room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "In a forest";

  long_desc =
    "You are in a big forest. As you breathe in the fresh air and "+
    "hear the animals of the forest, you get an overwelming sensation "+
    "of peacefulness.\n"; 

  items = ({
    "forest","It is big and smells quite nice",
  });

  dest_dir = ({
    FOREST + "wild1", "east",
    FOREST + "clearing", "west",
  });

  smell = "You smell the fresh air of the forest.";

  clone_list = ({
    1, 1, "leather jacket", "obj/armour", ({
      "set_name", "leather jacket",
      "set_short", "A leather jacket",
      "set_alias", "jacket",
      "set_long", "A worn but sturdy leather jacket.\n" +
        "On the back is a lot of rivets " +
        "making the pattern of a star.\n",
      "set_weight", 2,
      "set_value", 50,
      "set_size", 3,
      "set_ac", 2,
      "set_type", "armour/arm",
    }),
  });

  ::reset();
  replace_program("room/room");
}
