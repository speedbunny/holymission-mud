inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "A large open plain";

  long_desc =
    "Here, the forest clearing to the south opens up " +
    "into a wide open plain that stretches off " +
    "northwards for miles and miles.\n";

  dest_dir = ({
   PLAIN + "plain02", "north",
   FOREST + "clearing", "south",
  });

  items = ({
    "clearing", "To the south you can see a forest clearing",
  });

  clone_list = ({
    1, 1, "wolf", "obj/monster", ({
      "set_name", "wolf",
      "set_level", 3,
      "set_race", "wolf",
      "set_size", 3,
      "set_short", "A wolf",
      "set_long", "A grey wolf running around. " +
                  "It has some big dangerous teeth.\n",
      "set_wc", 7,
      "set_move_at_reset", 1,
      "set_whimpy", 30,
    }),
  });
                                      
  ::reset();
  replace_program("room/room");
}

