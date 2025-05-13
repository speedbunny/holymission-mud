inherit "/room/room";

#include "/room/room_defs.h"
#define WEAPONS   ({"axe","battleaxe","waraxe"})

void reset(int arg) {
  clone_list = ({
    1, 10, "large orc", "obj/monster", ({
      "set_name", "large orc",
      "set_race", "orc",
      "set_alt_name", "orc",
      "set_level", 6+random(9),
      "set_short", "A large orc",
      "set_long", "A disgusting large orc, drooling on himself while "+
        "waiting for his next meal.\n",
      "set_al", -160,
      "load_a_chat_array", ({ 30, ({
        "Large orc says: Halt! Intruder!\n",
        "Large orc says: Kill him quick and dirty.\n",
        "Large orc says: Where are our allies ?!\n",
        "Large orc says: Not again! I'm fed up with them.\n",
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
    ORC_VALLEY + "valley06", "north",
    ORC_VALLEY + "valley04", "east",
    ORC_VALLEY + "valley08", "west",
  });
 
  smell = "You smell the disgusting odor of urine and rotting meat.";
 
  items = ({
    "valley", "This is orc valley",
  });
 
  ::reset(arg);
  replace_program("/room/room");
}

