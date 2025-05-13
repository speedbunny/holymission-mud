inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "In a forest";

  long_desc =
    "You are in a big forest surrounded by many trees.\n";

  items = ({
    "forest","It is filled with trees",
    "trees","There are different varieties, making your travelling "+
      "more bearable",
  });

  dest_dir = ({
    FOREST + "clearing","east",
    FOREST + "forest09", "west",
  });

  smell = "You smell the fresh air of the forest.";

  clone_list = ({
    1, 1, "large troll", "obj/monster", ({
      "set_name", "troll",
      "set_alt_name", "large troll",
      "set_size", 4,
      "set_level", 7,
      "set_hp", 150,
      "set_wc", 12,
      "set_ac", 5,
      "set_al", -12,
      "set_short", "A large troll",
      "set_long", "It is a large, nasty troll that " +
        "looks very aggressive.\n",
      "set_race", "troll",
      "set_spell_mess1", "The troll says: Mumble",
      "set_spell_mess2", "The troll says: Your " +
        "mother was a bitch!",
      "set_chance", 20,
      "set_money", 500,
    }),
  });

  ::reset(arg);
  replace_program("room/room");
}
