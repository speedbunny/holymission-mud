inherit "/room/room";

#include <room_defs.h>

void reset(int arg){
  set_light(0);
  short_desc = "Dead end";
  long_desc =
    "The tunnel dead-ends here.\n";

  items = ({
    "tunnel", "It is dark",
  });

  dest_dir = ({
    MINES + "tunnel28", "west",
  });

  clone_list = ({
    1, 4, "roper", "obj/monster", ({
      "set_name", "roper",
      "set_level", 15,
      "set_race", "roper",
      "set_size", 3,
      "set_al", -200,
      "set_short", "A roper",
      "set_long", "A roper waiting for its food.\n",
      "set_aggressive", 1,
      "set_wc", 15,
      "set_ac", 10,
      "add_money", 400,
    }),
    -1, 1, "sapphire", "obj/treasure", ({
      "set_name", "sapphire",
      "set_id", "sapphire",
      "set_alias", "stone",
      "set_short", "A sapphire",
      "set_value", 250
    }),
    -1, 1, "diamond", "obj/treasure", ({
      "set_name", "diamond",
      "set_id", "diamond",
      "set_alias", "stone",
      "set_short", "A diamond",
      "set_value", 250
    })
  });

  ::reset(arg);
  replace_program("/room/room");
}

