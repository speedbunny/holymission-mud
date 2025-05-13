/*  This is the Mole Hole */

#include "/players/tamina/defs.h"

inherit "room/room";

void reset(int arg) {
 
  if (arg) return ;

      	set_light(0);
	short_desc = "Mole Hole";
	long_desc = 
"This is underground in a large mole's hole.\n"+
"You seem to have found the mole's lair, where her young \n"+
"are currently trying to remain alive.\n";

	dest_dir = ({
          CROOMS + "hole1","south",
        });

        clone_list = ({1, 4, "mole", "obj/monster",
  ({"set_name", "mole",
    "set_level", 3,
    "set_short", "Baby Mole",
    "set_long", 
    "A cute baby mole, with a little pink snout, \n"+
    "tiny little claws, and screwed-up pink eyes.   Awwwhh...\n",
    "set_aggressive", 0,
    "set_hp", 70,
    "set_wc", 7,
    "set_ac", 2,
    "set_gender", 1  }),
        });

    ::reset();

    RPR("room/room");

}
