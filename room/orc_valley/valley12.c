inherit "/room/room";
 
#include "/room/room_defs.h"

static int cnt1, cnt2, cnt3;
 
void reset(int arg) {
  cnt1 = 7 - random(3);
  cnt2 = 5 - random(3);
  cnt3 = 3 - random(3);
 
  clone_list = ({
    1, 1, "orc shaman", "/players/moonchild/pot/shaman", 0,
    2, cnt1, "normal orc", "obj/monster", ({
      "set_level", 4,
      "set_name", "orc",
      "set_alt_name", "normal orc",
      "set_long", "An ugly orc.\n",
      "set_aggressive", 1,
      "set_race", "orc",
    }),
    3, cnt2, "large orc", "obj/monster", ({
      "set_level", 7,
      "set_name", "large orc",
      "set_long", "A large ugly orc.\n",
      "set_aggressive", 1,
      "set_race", "orc",
    }),
    4, cnt3, "huge orc", "obj/monster", ({
      "set_level", 10,
      "set_name", "huge orc",
      "set_long", "A huge ugly orc.\n",
      "set_aggressive", 1,
      "set_race", "orc",
    }),
    -2, 1, "axe", "obj/weapon", ({
      "set_name", "hand axe",
      "set_alias", "axe",
      "set_long", "An orcish hand axe.\n",
      "set_class", 9,
      "set_weight", 2,
      "set_value", 25,
      "set_type", 1,
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
    -4, 1, "sword", "obj/weapon", ({
      "set_name", "sword",
      "set_short", "An orcish sword",
      "set_long", "A blunt orcish sword.\n",
      "set_class", 11,
      "set_weight", 2,
      "set_value", 200,
      "set_type", 0,
    }),
  });
 
  set_light(1);
  short_desc = "Orc valley";
  long_desc =
    "You are at the end of orc valley. Mountains rise " +
    "all around you, blocking the way forward except for a " +
    "pair of small trails leading west and south. " +
    "The overwhelming stench of orc urine gags you.\n";
 
  items = ({
    "trails", "They go west and south",
    "valley", "It is just a valley",
    "mountains", "Huge mountains bar exit to the north",
  });
 
  dest_dir = ({
    ORC_VALLEY + "valley11", "east",
    "players/tatsuo/area/forest1/road1", "west",
    ORC_VALLEY + "valley13", "south",
  });

  ::reset(arg);
  replace_program("room/room");
}
