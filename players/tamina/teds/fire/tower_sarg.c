inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Small Room";
    long_desc =
"This is a small cramped room. A hard cot takes up almost all of"+
"the north wall. The only other thing in the room is a short "+
"wooden stool in the corner. All in all, very uninteresting.\n";

    dest_dir = ({
      TFIRE + "tower3", "west"
    });

    clone_list =
  ({ 1, 1, "fire giant sergeant", "obj/monster",
    ({"set_name", "Fire Giant Sergeant",
      "set_alias", "sergeant",
      "set_short", "Fire Giant Sergeant",
      "set_long", 
        "This Fire Giant looks meaner and tougher than your average Fire Giant.\n",
      "set_race", "giant",
      "set_gender", 1,
      "set_level", 17,
      "set_wc", 25,
      "set_ac", 8,
      "set_al", -550,
      "set_whimpy", 25,
      "set_aggressive", 1, 
      "set_spell_mess2", "The Sergeant smashes you in the face with his fist.\n",
      "set_spell_mess1", "The Sergeant's fists fly.\n",
      "set_spell_dam", 30,
      "set_chance", 45,
    }),
    -1, 1, "longsword", "obj/weapon",
    ({"set_name", "Fire Giant's Longsword", 
      "set_short", "A Fire Giant's Longsword",
      "set_long", 
        "This longsword seems heavier and larger than your average sword.\n",
      "set_class", 13,
      "set_weight", 3,
      "set_value", 500,
    }),
  });

    ::reset(arg);
    RPR("room/room");
}
