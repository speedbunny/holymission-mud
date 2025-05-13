inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "A Guard Room";
    long_desc =
"This room smells as if a number of unbathed men have spent\n"+
"a very long time here. There are signs of a recently disturbed\n"+
"poker game. Cots and bed rolls lie in one corner of the room.\n";

    dest_dir = ({
     TFIRE + "gate","south",
     TFIRE + "courtyard","north"
    });

    items = ({
  "bed rolls",
"These are hard wooden planks covered by a thin layer "+
"of padding. They look very uncomfortable",
  "cots",
"These are hard wooden planks covered by a thin layer "+
"of padding. They look very uncomfortable",
  "poker",
"This is a game played with cards. As the cards are delt, the "+
"people playing bet coins on what their cards are. (Very Primitive)",
  "game",
"This is a game played with cards. As the cards are delt, the "+
"people playing bet coins on what their cards are. (Very Primitive)"
    });

    clone_list =
  ({ 1, 3, "guard", "obj/monster",
    ({"set_name", "fire giant guard",
      "set_alias", "guard",
      "set_race", "giant",
      "set_gender", 1,
      "set_short", "A Fire Giant Guard",
      "set_long", "This is an ugly, smelly guard, that looks quite mean.\n",
      "set_level", 14,
      "set_wc", 25,
      "set_ac", 6,
      "set_al", -450,
      "set_whimpy", 25,
      "set_aggressive", 1,
    }),
    -1, 1, "longsword", "obj/weapon",
    ({"set_name", "Fire Giant Longsword", 
      "set_alias", "longsword",
      "set_short", "A Fire giant's Longsword",
      "set_long", "A heavy, but sharp looking longsword",
      "set_class", 13,
      "set_weight", 4,
      "set_value", 500,
    }),
    -1, 1, "shield", "obj/armour", 
    ({"set_name", "Fire Giant Shield", 
      "set_type", "shield",
      "set_short", "A Fire Giant's Shield",
      "set_long", "A large, circular shield.\n",
      "set_ac", 1,
      "set_weight", 2,
      "set_value", 250,
    }),
  });

    ::reset(arg);
    RPR("room/room");
}

