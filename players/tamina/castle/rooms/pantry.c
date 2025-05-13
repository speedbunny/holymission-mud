#include "/players/tamina/defs.h"

inherit "room/room";

void reset (int arg) {

  if (arg) return ;

    set_light(0);
    short_desc = "Pantry ";
    long_desc = 
  "You pass into the pantry of the large kitchen, and are immediately\n"+
  "overcome by the awful stench of rotten food in this room!  Shelves \n"+
  "the walls, which are laden with maggot-ridden pieces of dried-meat, \n"+
  "and over-ripe pieces of fruit full of worms.\n";

    dest_dir = ({CROOMS + "kitchen", "out",
     });

    items = ({
  "shelves",
"Large wooden slats crammed with decayed food, and worms feasting on them",
  "food",
"GROSS!!!  Ancient bits of mouldy, rotten food, covered in all manner "+ 
"of creepy, wriggly things!!",
     });

    clone_list = ({1, 5, "maggot", "obj/monster",
({"set_name", "maggot",
  "set_level", 2,
  "set_short", "Maggot",
  "set_long", "A small, wriggly maggot.\n",
  "set_aggressive", 1,
  "set_hp", 30,
  "set_wc", 6,
  "set_ac", 2  }),
                  2, 3, "worm", "obj/monster",
({"set_name", "worm",
  "set_alias", "small",
  "set_level", 1,
  "set_short", "Small Worm",
  "set_long", "A small, wriggly worm.\n",
  "set_aggressive", 0,
  "set_hp", 50,
  "set_wc", 5,
  "set_ac", 0  }),
                  3, 3, "medium worm", "obj/monster",
({"set_name", "medium worm",
  "set_alias", "worm",
  "set_alt_name", "medium",
  "set_level", 3,
  "set_short", "Worm",
  "set_long", "A medium-sized worm that looks hungry.\n",
  "set_aggressive", 1,
  "set_hp", 70,
  "set_wc", 7,
  "set_ac", 2  }),
                  4, 2, "giant worm", "obj/monster",
({"set_name", "giant worm",
  "set_alias", "worm",
  "set_alt_name", "giant",
  "set_level", 8,
  "set_short", "Giant Worm",
  "set_long", 
  "A devilishly large mutant worm, that looks as though it\n"+
  "could bite your head off!\n",
  "set_aggressive", 1,
  "set_hp", 130,
  "set_wc", 11,
  "set_ac", 3,
  "set_spell_mess2", "The Giant Worm digests you!!\n",
  "set_spell_mess1", "The Giant Worm tries to digest its prey!\n",
  "set_spell_dam", 8 + random(16),
  "set_chance", 4,
  "add_money", 80  }),
  });

  ::reset();

  replace_program("room/room");

}
