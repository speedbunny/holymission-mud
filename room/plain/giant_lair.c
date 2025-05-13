inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "Lair of the Giant";

  long_desc =
    "You have entered a large area in the hills. The path "+
    "continues east into the plains and to the west leads further "+
    "into the hills.\n";

  dest_dir = ({
    PLAIN + "giant_path", "east",
    PLAIN + "giant_conf", "west",
  });

  items = ({
    "hills", "They are foothills that grow into mountains",
    "plains", "They are to the east",
    "path", "It goes both east and west",
    "area", "It looks to be the home of some giant",
  });

  clone_list = ({
    1, 1, "hill giant", "obj/monster", ({
      "set_name", "hill giant",
      "set_level", 15,
      "set_race", "giant",
      "set_size", 4,
      "set_short", "A very ugly hill giant",
      "set_long", "This ugly speciman of the giant not only looks "+
        "tough, but smells almost as tough.\n",
      "set_str", 35,
      "set_wc", 15,
      "set_ac", 5,
      "set_aggressive", 1,
    }),
  });

  ::reset();
  replace_program("room/room");
}
