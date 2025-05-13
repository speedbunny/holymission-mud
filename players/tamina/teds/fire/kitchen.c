inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  ::reset(arg);
    set_light(1);
    short_desc = "Small Kitchen";
    long_desc =
"This is a small kitchen. Pots and pans are stacked on shelves\n"+
"while herbs and spices sit in small glass containers on the\n"+
"counter. An empty bottle sits next to them on the counter.\n";

    dest_dir = ({
      TFIRE + "whall2", "south"
    });

    items = ({
  "glass", 
"This bottle used to contain some type of alcohol.......",
  "bottle", 
"This bottle used to contain some type of alcohol......."
    });

    clone_list = 
  ({ 1, 1, "cook", "obj/monster", 
    ({"set_name", "Fire Giant Cook",
      "set_alias", "cook",
      "set_short", "Fire Giant Cook",
      "set_long", "After the bug was found, this room finally got a long desc....\n",
      "set_race", "giant",
      "set_gender", 1,
      "set_level", 8,
      "set_wc", 15,
      "set_ac", 2,
      "set_spell_mess1", "The Cook throws a pot of boiling water across the room.\n",
      "set_spell_mess2", "The Cook spills boiling water all over you !!\n",
      "set_spell_dam", 10,
      "set_chance", 35,
      "set_whimpy", 25,
      "set_aggressive", 1, 
      "set_al", -250,
    }),
  });

  RPR("room/room");
}
