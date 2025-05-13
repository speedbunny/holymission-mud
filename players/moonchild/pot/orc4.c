inherit "room/room";

reset(arg) {

  set_light(1);
  short_desc="Orc valley";
  long_desc="You are in the orc valley. This place in inhabited by orcs.\n"	+
    "Your nose is tortured by the strong smell of orc urine.\n" +
    "To the south stands a sheer rock wall.\n";
  items=({ "building", "This is the hall of the unknown" });
  dest_dir=({ "players/moonchild/pot/orc3", "north", });

  clone_list = ({
    1, 4, "normal orc", "obj/monster", ({
      "set_level", 4,
      "set_name", "orc",
      "set_alt_name", "normal orc",
      "set_long", "An ugly orc.\n",
      "set_aggressive", 1,
      "set_race", "orc",
    }),
    2, 1, "large orc", "obj/monster", ({
      "set_level", 7,
      "set_name", "large orc",
      "set_long", "A large ugly orc.\n",
      "set_aggressive", 1,
      "set_race", "orc",
    }),
    3, 1, "huge orc", "obj/monster", ({
      "set_level", 10,
      "set_name", "huge orc",
      "set_long", "A huge ugly orc.\n",
      "set_aggressive", 1,
      "set_race", "orc",
    }),
    -1, 1, "axe", "obj/weapon", ({
      "set_name", "hand axe",
      "set_alias", "axe",
      "set_long", "An orcish hand axe.\n",
      "set_class", 9,
      "set_weight", 2,
      "set_value", 25,
      "set_type", 1,
    }),
    -2, 1, "sword", "obj/weapon", ({
      "set_name", "sword",
      "set_short", "An orcish sword",
      "set_long", "A blunt orcish sword.\n",
      "set_class", 11,
      "set_weight", 2,
      "set_value", 200,
      "set_type", 0,
    }),
    -3, 1, "sword", "obj/weapon", ({
      "set_name", "sword",
      "set_short", "An orcish sword",
      "set_long", "A blunt orcish sword.\n",
      "set_class", 11,
      "set_weight", 2,
      "set_value", 200,
      "set_type", 0,
    }),
  });

  ::reset(arg);
  replace_program("room/room");
}
