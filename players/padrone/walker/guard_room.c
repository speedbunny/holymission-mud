/* guard_room.c */
/* Recode - Exos 961026 */

inherit "/room/room";
#include "walker.h"

void reset(int flag) {
    if(!flag) {
	set_light(1);
	dest_dir = ({   
	  "players/padrone/walker/gate_room", "west",
	});
	short_desc="In the guard room";
	long_desc =
	"You are in a small guard room east of the gate room in the\n" +
	"walking castle. The castle guards used to stay here, but now\n" +
	"they have been killed or driven away by the pirates.\n";
	clone_list=({
	  1, 1, "pirate1", "/players/padrone/monsters/bigger_pirate", 0,
	  2, 1, "pirate2", "/players/padrone/monsters/big_pirate", 0,
	  -1, 1, "axe", "/players/padrone/obj/handaxe", 0,
	  -2, 1, "knife", "/players/padrone/obj/knife", 0,
	  -2, 1, "helmet", "/players/padrone/obj/helmet", 0,
	});
    }
    ::reset(flag);
    replace_program("room/room");
}
