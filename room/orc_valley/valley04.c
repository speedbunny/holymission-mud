inherit "/room/room";

#include "/room/room_defs.h"
#define WEAPONS   ({"spear","large spear","orcish spear"})
 
void reset(int arg) {
  clone_list = ({
    1, 3, "medium orc", "obj/monster", ({
      "set_name", "orc",
      "set_race", "orc",
      "set_alt_name", "medium orc",
      "set_level", 6+random(5),
      "set_short", "An orc",
      "set_long", "A disgusting orc, drooling on himself while waiting "+
        "for his next meal.\n",
      "set_al", -60,
      "load_a_chat_array", ({ 30, ({
        "Orc says: Now look at this disgusting adventurer!\n",
        "Orc farts right into your face.\n",
        "Orc says: Ash! Lugburz, ghaan Kuttln!\n",
        "Orc sniffs in your direction.\n",
        "Orc says: This one makes me vomit.\n",
        "Orc pukes on your shirt.\n" 
      }) }),
      "set_move_at_reset", 1,
      "set_aggressive", 1,
    }),
    -1, 1, "spear", "obj/weapon", ({
      "set_name", WEAPONS[random(3)],
      "set_class", 8+random(6),
      "set_value", 55+random(81),
      "set_weight", 2+random(2),
      "set_alt_name", "spear",
      "set_type", 0,
      "set_two_handed", 1,
    }),
  });
 
  set_light(1);
 
  short_desc = "The orc valley";
  long_desc =
    "You are in the orc valley. It is a narrow valley stretching east "+
    "and west, and is inhabited by orcs "+
    "and ogres. The stench here makes it difficult to breathe.\n";
 
  dest_dir = ({
    ORC_VALLEY + "valley03", "east",
    ORC_VALLEY + "valley05", "west",
  });
 
  smell = "You smell the disgusting odor of urine and rotting meat.";
 
  items = ({
    "valley", "This is orc valley",
  });
 
  ::reset(arg);
  replace_program("/room/room");
}

