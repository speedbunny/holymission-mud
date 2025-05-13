inherit "/room/room";

#include "/room/room_defs.h"
#define WEAPONS   ({"knife","hatchet","hand axe"})

void reset(int arg) {
  clone_list = ({
    1, 7, "small orc", "obj/monster", ({
      "set_name", "orc",
      "set_race", "orc",
      "set_alt_name", "small orc",
      "set_level", 1+random(4),
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
    ORC_VALLEY + "valley02", "east",
    ORC_VALLEY + "valley04", "west",
  });
 
  smell = "You smell the disgusting odor of urine and rotting meat.";
 
  items = ({
    "valley", "This is orc valley",
  });
 
  ::reset(arg);
  replace_program("/room/room");
}

