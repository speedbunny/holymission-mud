inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    if (arg) return;
    set_light(1);
    short_desc = "Petrified Forest";
    long_desc =
"You are in the depths of the Petrified Forest.\n"+
"To the south you can see a large throne in a clearing.\n"+
"A large mountain stands to the west, barring any progress.\n";

    dest_dir = ({
    TFOREST + "rmS", "north",
    TFOREST + "rmG", "south",
    });

    clone_list = ({1, 1, "captain", "obj/monster",
({"set_name", "orcish captain", 
  "set_alias", "captain",
  "set_race", "orc", 
  "set_level", 12, 
  "set_short", "Orcish Captain", 
  "set_long", "This very large Orc looks very imposing.\n", 
  "set_aggressive", 1, 
  "set_wc", 12, 
  "set_ac", 4, }),
                 2, 1, "hero", "obj/monster",
({"set_name", "orcish hero", 
  "set_alias", "hero",
  "set_race", "orc", 
  "set_level", 9, 
  "set_short", "Orcish Hero", 
  "set_long", 
   "This impressive orc is wearing good armour, and wielding a good weapon.\n", 
  "set_aggressive", 1, 
  "set_wc", 10, 
  "set_ac", 4, }),
               -2, 1, "scimitar", "obj/weapon",
({"set_name", "orcish scimitar",
  "set_alt_name", "scimitar",
  "set_alias", "sword",
  "set_short", "Orcish Scimitar",
  "set_long", "This is an evil looking curved sword, wielded by Orcs.\n",
  "set_weight", 2,
  "set_value", 750,
  "set_class", 15, }),
              -2, 1, "mail", "obj/armour", 
({"set_name", "orcish chainmail",
  "set_alias", "chainmail",
  "set_short", "Orcish Chainmail",
  "set_long", "This chainmail is very effective.\n",
  "set_weight", 3, 
  "set_ac", 3, 
  "set_type", "armour", }), 
  });

    ::reset();
    replace_program("room/room");
}
