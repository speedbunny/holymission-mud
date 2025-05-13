/*  This is a Hole [down from the courtyard]  */

#include "/players/tamina/defs.h"

inherit "room/room";

void reset(int arg) {
  if (arg) return ;

      	set_light(-2);
	short_desc = "Mole Hole";
	long_desc = 
"You have just fallen into a hole dug by a rather\n"+
"large, and now, angry mole!\n";

	dest_dir = ({
          CROOMS + "wcourt2","up",
          CROOMS + "hole2","north",
        });

	clone_list = ({ 1, 1, "mole", "obj/monster", 
  ({"set_name", "mole",
    "set_short", "A Mole",
    "set_long", "A large furry, with a pointy little snout.\n",
    "set_level", 12,
    "set_gender", 2,
    "set_aggressive", 1,
    "set_hp", 300,
    "set_wc", 15,
    "set_ac", 5,
    "add_money", 120, }), 
    });

    	::reset();

	RPR("room/room");
}
