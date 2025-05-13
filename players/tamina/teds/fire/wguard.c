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
      TFIRE + "whall3", "north"
    });

    items = ({
"cots","These are hard wooden planks covered by a thin layer "+
       "of padding. They look very uncomfortable",
"beds","These are hard wooden planks covered by a thin layer "+
       "of padding. They look very uncomfortable",
"game","This is a game played with cards. As the cards are dealt, the ",
        "people playing bet coins on what their cards are.(Very Primitive)"
    });

     clone_list =
  ({ 1, 3, "fire giant guard", "obj/monster", 
    ({"set_name", "fire giant guard",
      "set_alias", "guard",
      "set_race", "giant",
      "set_gender", 1,
      "set_short", "Fire Giant Guard",
      "set_long",
        "This is a smelly, dirty fire giant.  He is about 10 feet tall,\n"+
        "and must weigh about 400 pounds.  He does not look happy that\n"+
	"you are here.\n",
      "set_level", 14,
      "set_wc", 25,
      "set_ac", 6,
      "set_whimpy", 25,
      "set_aggressive", 1,
      "set_al", -450,
    }),
    -1, 1, "longsword", "obj/weapon",
    ({"set_name", "Fire Giant's Longsword",
      "set_alt_name", "sword",
      "set_short", "A Fire Giant's Longsword",
      "set_long", "This longsword looks very heavy, but very sharp.\n",
      "set_class", 13,
      "set_weight", 4,
      "set_value", 500,
    }),
    -1, 1, "shield", "obj/armour",
    ({"set_name", "Fire Giant Shield",
      "set_type", "shield",
      "set_short", "A Fire Giant's Shield",
      "set_long", "This is a huge red shield...Crude but effective.\n",
      "set_ac", 1,
      "set_weight", 3,
      "set_value", 100,
    }),
  });

    ::reset(arg);
    RPR("room/room");
}
