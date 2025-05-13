/* Castle Yard */
/* REcode - Exos 961026 */

inherit "/room/room";
#include "walker.h"

void reset(int flag) {
    if(!flag) {
	set_light(1);
	dest_dir=({
	  "players/padrone/walker/gate_room", "south",
	  "players/padrone/walker/main_hall", "north",
	  "players/padrone/walker/shop", "west",
	  "players/padrone/walker/pub", "east",
	});
	short_desc = "The castle yard of the walking castle";
	long_desc =
	"You are in the castle yard of the walking castle.\n" +
	"Once this was a nice place, with beautiful flowers, sculptures\n" +
	"and a fountain, but the pirates have eaten the flowers,\n" +
	"broken the sculptures, and polluted the fountain.\n";
	clone_list=({
	  1, 1, "pirate", "/players/padrone/monsters/fat_pirate", 0,
	  -1, 1, "knife", "/players/padrone/obj/knife", 0,
	  -1, 1, "helmet", "/players/padrone/obj/helmet", 0,
	});
    }
    ::reset(flag);
    replace_program("room/room");
}
