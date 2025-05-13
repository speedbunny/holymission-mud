/* Pub */
/* Recode - Exos 961028 */

inherit "/room/room";
#include "walker.h"

void reset(int arg) {
    if(!arg) {
	set_light(1);
	dest_dir = ({
	  "players/padrone/walker/castle_yard", "west",
	});
	short_desc ="The pub of the walking castle";
	long_desc =
	"You are in what used to be the pub of the walking castle.\n" +
	"This was once a nice and cosy place, where you could take\n" +
	"beer or a cup of coffee and chat with your friends. Now the\n" +
	"pirates have drunk absolutely everything drinkable, broken\n" +
	"the empty bottles, and written rude comments on the walls.\n";
	clone_list=({
	  1, 1, "pirate1", "/players/padrone/monsters/completely_drunk_pirate", 0,
	  -1, 1, "cutlass", "/players/padrone/obj/cutlass", 0,
	  2, 1, "pirate2", "/players/padrone/monsters/very_drunk_pirate_indeed", 0,
	  2, 1, "pirate3", "/players/padrone/monsters/moderately_drunk_pirate", 0,
	  -2, 1, "knife", "/players/padrone/obj/knife", 0,
	  -2, 1, "helmet", "/players/padrone/obj/helmet", 0,
	  3, 1, "pirate4", "/players/padrone/monsters/very_drunk_pirate", 0,
	  -3, 1, "cknife", "/players/padrone/obj/cknife", 0,
	  4, 1, "pirate5", "/players/padrone/monsters/more_drunk_pirate", 0,
	  -4, 1, "axe", "/players/padrone/obj/handaxe", 0,
	});
    }
    ::reset(arg);
    replace_program("room/room");
}
