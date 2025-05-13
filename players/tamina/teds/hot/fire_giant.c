inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Tar Pit";
    long_desc =
    "A large lizard like creature is halfway embedded in\n"+
    "a huge pool of black tar. It looks as if it was\n"+
    "chased into the pool.\n";

    dest_dir = ({
      THOT + "fire_forest","south",
      TFIRE + "gate","north"
    });

    items = ({
      "lizard","A large, red lizard. It is dead and has had pieces of its"+
      "hide removed. It's out of reach, embedded in the pool",
      "pool","A large pool of tar, black and sticky"
    });

    clone_list = ({
      1, 2, "fire giant scout", "obj/monster",
  ({"set_name", "fire giant scout",
    "set_alias", "scout",
    "set_race", "giant", 
    "set_gender", 1, 
    "set_long", 
  "This is a large fire giant scout.  He looks\n"+
  "reasonably intelligent.\n", 
    "set_level", 16, 
    "set_wc", 20, 
    "set_ac", 4, 
    "set_al", -150, 
    "set_aggressive", 1, }),
     -1, 1, "sword of fire", "/players/tamina/teds/weapons/sword_of_fire", 0,
      2, 2, "female fire giant", "/players/tamina/teds/monsters/female_fire_giant", 0,
    });

    ::reset(arg);

    replace_program("room/room");
}
