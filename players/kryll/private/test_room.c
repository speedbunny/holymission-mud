inherit "/room/room";
 
#define WEAPONS   ({"knife","hatchet","hand axe"})
 
void reset(int arg) {
  clone_list = ({
    1, 5, "small orc", "/players/kryll/private/monster", ({
      "set_name", "orc",
      "set_race", "orc",
      "set_alt_name", "small orc",
      "set_level", 1+random(3),
      "set_short", "An orc",
      "set_long", "A disgusting orc, drooling on himself while waiting "+
        "for his next meal.\n",
      "set_al", -60,
      "load_a_chat_array", ({ 30, ({
        "Orc says: Yummy, here comes a little snack !\n",
        "Orc says: Tell Shaggratt to heat the oven !\n",
        "Orc says: Get lost, crap !\n",
        "Orc says: Shall we eat him raw ?\n",
        "Orc says: Bah, I don't like it when the food smells this way.\n"
      }) }),
      "set_move_at_reset", 1,
      "set_aggressive", 1,
    }),
    -1, 1, "axe", "obj/weapon", ({
      "set_name", WEAPONS[random(3)],
      "set_class", 5+random(5),
      "set_value", 15+random(11),
      "set_weight", 1+random(2),
      "set_alt_name", "axe",
      "set_type", 2,
    }),
  });
 
  set_light(1);
 
  short_desc = "The orc valley";
  long_desc =
    "You are in the orc valley. It is a narrow valley stretching east "+
    "and west, and is inhabited by orcs "+
    "and ogres. The stench here makes it difficult to breathe.\n";
 
  dest_dir = ({
  });
 
  smell = "You smell the disgusting odor of urine and rotting meat.";
 
  items = ({
    "valley", "This is orc valley",
  });
 
  ::reset(arg);
  replace_program("/room/room");
}
