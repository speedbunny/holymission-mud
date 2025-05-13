inherit "/room/room";

#include "/room/room_defs.h"

static int cnt1, cnt2, cnt3;

void reset(int arg) {
  cnt1 = 7 - random(3);
  cnt2 = 5 - random(3);
  cnt3 = 3 - random(3);

  clone_list = ({
    1, cnt1,  "normal orc", "obj/monster", ({
      "set_level", 5,
      "set_name", "orc",
      "set_alt_name", "normal orc",
      "set_long", "An ugly orc.\n",
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
    2, cnt2, "large orc", "obj/monster", ({
      "set_level", 12,
      "set_name", "large orc",
      "set_long", "A large ugly orc.\n",
      "set_aggressive", 1,
      "set_race", "orc",
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
    3, cnt3, "huge orc", "obj/monster", ({
      "set_level", 20,
      "set_name", "huge orc",
      "set_long", "A huge ugly orc.\n",
      "set_aggressive", 1,
      "set_race", "orc",
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
  set_light(1);
  short_desc="Orc valley";

  long_desc=
    "You are in the orc valley. This place is inhabited by orcs. "+
    "Your nose is tortured by the strong smell of orc urine. "+
    "To the west, you can see a lot of stones on the ground.\n";

  items=({
    "valley", "It runs east and west",
    "stones", "There are lots of stones on the ground",
    "ground", "There are lots of stones on the ground",
  });

  smell = "You smell the disgusting odor of urine.";

  dest_dir=({
    ORC_VALLEY + "valley10", "east",
    ORC_VALLEY + "valley12", "west",
    "players/nylakoorub/clearing/path/rooms/c006", "north",
  });

  ::reset(arg);
  replace_program("/room/room");
}
