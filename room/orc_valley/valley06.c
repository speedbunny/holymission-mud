inherit "/room/room";
 
#include "/room/room_defs.h"
#define WEAPONS   ({"club","large club","war club"})
 
void reset(int arg) {
  clone_list = ({
    1, 3, "large ogre", "obj/monster", ({
      "set_name", "ogre",
      "set_race", "ogre",
      "set_alt_name", "large ogre",
      "set_level", 10+random(9),
      "set_short", "A large ogre",
      "set_long", "A disgusting large ogre, just waiting to brain the "+
        "next helpless soul.\n",
      "set_al", -350,
      "set_str", 23+random(8),
      "set_move_at_reset", 1,
      "set_aggressive", 1,
    }),
    -1, 1, "club", "obj/weapon", ({
      "set_name", WEAPONS[random(3)],
      "set_class", 9+random(6),
      "set_value", 20+random(101),
      "set_weight", 4+random(3),
      "set_alt_name", "club",
      "set_type", 0,
    }),
  });
 
  set_light(1);
 
  short_desc = "The orc valley";
  long_desc =
    "You are in the orc valley. This happens to be one of the hangouts "+
    "for the orc's allies.\n";
 
  dest_dir = ({
    ORC_VALLEY + "valley07", "west",
    ORC_VALLEY + "valley05", "south",
  });
 
  smell = "You smell the disgusting odor of urine and rotting meat.";
 
  items = ({
    "valley", "This is orc valley",
  });
 
  ::reset(arg);
  replace_program("/room/room");
}

