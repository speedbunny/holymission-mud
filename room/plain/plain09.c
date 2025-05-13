inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "A large open plain";

  long_desc =
    "The eastern edge of this deserted open plain " +
    "is bordered by a river here. Towards the west, " +
    "you can see the disintegrating remains of an " +
    "old ruined building.\n";

  dest_dir = ({
    PLAIN + "ruin", "west",
  });

  items = ({
    "plain", "The plain stretches to the west",
    "river", "The river looks to be some ten feet below you. " +
      "It is flowing quite fast",
    "building", "It looks like it was once a farm building",
    "bank", "The river bank below you is crumbling away",
    "river bank", "The river bank below you is crumbling away",
  });

  clone_list = ({
    1, 1, "frog", "obj/monster", ({
      "set_name", "frog",        
      "set_level", 1,
      "set_wc", 4, 
      "set_frog", 1,
      "set_size", 1,
      "set_short", "A cute little frog",
      "set_long", "A cute little frog. It looks rather friendly.\n",
    }),
    -1, 1, "crown", "obj/treasure", ({
      "set_name", "crown",
      "set_alias", "iron crown",
      "set_value", 30,
      "set_short", "An iron crown",
    }), 
  });

  ::reset();
  replace_program("room/room");
}

