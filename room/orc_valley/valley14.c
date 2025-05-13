inherit "room/room";

#include "/room/room_defs.h"
 
void reset(int arg) {
  clone_list = ({
    1, 5, "huge orc", "obj/monster", ({
      "set_level", 20 + random(6),
      "set_name", "huge orc",
      "set_long", "A huge ugly orc.\n",
      "set_race", "orc",
      "set_ac", 5,
      "set_str", 25,
      "set_aggressive", 1,
    }),
    -1, 1, "sword", "obj/weapon", ({
      "set_name", "sword",
      "set_short", "An orcish sword",
      "set_long", "A blunt orcish sword.\n",
      "set_class", 11 + random(9),
      "set_weight", 4+random(4),
      "set_value", 200+random(400),
      "set_size", 4,
      "set_type", 0,
    }),
  });
 
  ::reset(arg);
  if(arg) return;
 
  set_light(1);
  short_desc = "Orc valley";

  long_desc =
    "You are in the orc valley. This place is inhabited by orcs. "+
    "Your nose is tortured by the strong smell of orc urine. "+
    "To the south stands a large building carved out of sheer rock.\n";

  items = ({
    "valley", "It continues north",
    "rock", "The building is made out of it",
    "building", "This is the hall of the unknown",
  });

  dest_dir = ({
    ORC_VALLEY + "valley13", "north",
  });
}

