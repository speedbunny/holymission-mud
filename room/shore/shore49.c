inherit "/room/room";

#include <room_defs.h>

void reset(int arg) {
  clone_list = ({
    1, random(4), "Seagull", "obj/monster", ({
      "set_name", "seagull",
      "set_level", 1 + random(5),
      "set_race", "bird",
      "set_alias_list", ({ "gull", "Seagull" }),
      "set_gender", 1 + random(2),
      "set_short", "A seagull",
      "set_long", "A salty seagull looking for something to eat.\n",
      "load_chat_array", ({ 20, ({
        "Seagull squawks happily.\n",
        "Seagull snaps its beak.\n",
        "Seagull seems to grin at you.\n",
        "Seagull flies past you, squawking.\n" })
      }),
      "set_al", -10 + random(21),
    })
  });

  ::reset(arg);
  set_light(1);

  short_desc="Ocean shore";

  long_desc =
    "You are on the road leading south next to the ocean shore. "+
    "Huge waves roll toward the land. You notice seagulls in "+
    "the far distance.\n";


  dest_dir = ({
    SHORE + "shore48", "north",
    SHORE + "shore50", "southeast",
  });

  items = ({
    "road", "The road continues along the coast",
    "coast", "It occurs when land meets an ocean",
    "seagulls", "They are usually found near salt water",
    "ocean", "The wild blue ocean",
    "waves", "They roll and roll and roll and ....",
    "land", "You are standing on it",
    "birds", "Seems to be a group of seagulls",
  });

  replace_program("room/room");
}
