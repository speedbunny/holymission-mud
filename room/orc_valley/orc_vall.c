inherit "/room/room";

#include "/room/room_defs.h"

#define WEAPONS ({"knife", "hatchet", "handaxe"})

void reset(int arg) {
  clone_list = ({
    1, 8, "small orc", "obj/monster", ({
      "set_name", "orc",
      "set_race", "orc",
      "set_alias_list", ({ "small orc" }),
      "set_level", 1 + random(3),
      "set_short", "A small orc",
      "set_long", "A disgusting orc, drooling on himself while "+
        "waiting for his next meal.\n",
      "set_al", -60,
      "load_a_chat_array", ({ 30, ({
        "Orc says: Yummy, here comes a little snack!\n",
        "Orc says: Tell Shaggratt to heat the oven!\n",
        "Orc shouts: Get lost, crap!\n",
        "Orc asks: Shall we eat him raw?\n",
        "Orc says: Bah, I don't like it when the food smells this way.\n",
      }) }),
      "set_move_at_reset", 1,
      "set_aggressive", 1,
    }),
    -1, 1, "axe", "obj/weapon", ({
      "set_name", WEAPONS[random(3)],
      "set_class", 5 + random(5),
      "set_value", 15 + random(11),
      "set_weight", 1 + random(2),
      "set_alt_name", "axe", 
      "set_type", 2,
    }),
  });

  set_light(1);
  short_desc="The orc valley";
  long_desc=
    "You are in the orc valley. This place is inhabited " +
    "by orcs. There is a fortress to the north, with " +
    "lots of signs of orcs.\n";

  items=({
    "valley", "Well, it would be pretty, if it wasn't for those orcs..",
    "place", "It's a valley",
    "fortress", "It looks dangerous",
    "signs", "Well, the smell is unmistakable",
  });

  dest_dir=({
    ORC_VALLEY + "fortress", "north",
    ORC_VALLEY + "valley01", "west",
//    FOREST + "slope", "east",
    "/room/slope", "east",
  });

  ::reset(arg);
  replace_program("/room/room");
}

