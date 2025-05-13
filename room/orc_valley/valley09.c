inherit "/room/room";
 
#include "/room/room_defs.h"
#define WEAPONS   ({"axe","battleaxe","waraxe"})
 
void reset(int arg) {
  clone_list = ({
    1, 8, "huge orc", "obj/monster", ({
      "set_name", "huge orc",
      "set_race", "orc",
      "set_alt_name", "orc",
      "set_level", 10+random(9),
      "set_short", "A huge orc",
      "set_long", "A disgusting huge orc, drooling on himself while "+
        "waiting for his next meal.\n",
      "set_al", -560,
      "set_ac", 5,
      "set_size", 4,
      "set_str", 23+random(5),
      "load_a_chat_array", ({ 30, ({
        "Huge orc says: Halt! Intruder!\n",
        "Huge orc says: Kill him quick and dirty.\n",
        "Huge orc says: Where are our allies ?!\n"
      }) }),
      "set_move_at_reset", 1,
      "set_aggressive", 1,
    }),
    -1, 1, "axe", "obj/weapon", ({
      "set_name", WEAPONS[random(3)],
      "set_class", 9+random(6),
      "set_value", 100+random(101),
      "set_weight", 2+random(3),
      "set_alt_name", "axe",
      "set_type", 1,
      "set_size", 4,
    }),
    -1, 1, "chainmail", "obj/armour", ({
      "set_name", "orcish chainmail",
      "set_alt_name", "chainmail",
      "set_short", "Large orcish chainmail",
      "set_long", "This is a large suit of orcish chainmail. It must "+
        "have been made for an extremely large orc.\n",
      "set_ac", 4,
      "set_size", 4,
      "set_type", "armour",
      "set_weight", 7,
    }),
  });
 
  set_light(1);
 
  short_desc = "The orc valley";
  long_desc =
    "You are in the orc valley. It is a narrow valley stretching east "+
    "and west, and is inhabited by orcs "+
    "and ogres. The stench here makes it difficult to breathe.\n";
 
  dest_dir = ({
    ORC_VALLEY + "valley08", "east",
    ORC_VALLEY + "valley10", "west",
  });
 
  smell = "You smell the disgusting odor of urine and rotting meat.";
 
  items = ({
    "valley", "This is orc valley",
  });
 
  ::reset(arg);
  replace_program("/room/room");
}

