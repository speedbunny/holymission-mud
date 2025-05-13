#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Tar Pit";
    long_desc =
    "A large lizard like creature is halfway embedded in\n"+
    "a huge pool of black tar. It looks as if it was\n"+
    "chased into the pool.\n";
    dest_dir = ({
      HOT + "fire_forest","south",
      FIRE + "gate","north"
    });
    items = ({
      "lizard","A large, red lizard. It is dead and has had pieces of its"+
      "hide removed. It's out of reach, embedded in the pool",
      "pool","A large pool of tar, black and sticky"
    });
    clone_list = ({
      1,2,"fire giant scout","players/ted/monsters/fire_giant_scout",0,
      -1,1,"sword of fire","players/ted/weapons/sword_of_fire",0,

      2,2,"female fire giant","players/ted/monsters/female_fire_giant",0,
    });
    ::reset();
    replace_program("room/room");
}
