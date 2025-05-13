inherit "/room/room";
// inherit "players/cashimor/inherit/water";

#include <room_defs.h>

void reset(int arg) {
  set_light(1);
  short_desc = "Sea bottom";

  long_desc =
    "You are on the bottom of the sea.\n";

  dest_dir = ({
    EAST + "sea", "up",
  });

  items = ({
    "sea", "It's vibrating with green life",
  });

  clone_list = ({
    1, 1, "Octopus", "obj/monster", ({
      "set_name", "octopus",
      "set_level", 9,
      "set_alias_list", ({ "Octopus" }),
      "set_race", "fish",
      "set_size", 4,
      "set_al", -20,
      "set_short", "An octopus",
      "set_long", "A very big octopus with long tentacles.\n",
      "set_spell_mess1", "The octopus says: Mumble",
      "set_spell_mess2", "The octopus says: I will crush you to a pulp!",
      "set_chance", 20,
      "set_has_gills", 1,
      "set_wc", 12,
      "add_money", 500,
    }),
  });

  ::reset(arg);
  replace_program("room/room");
}

