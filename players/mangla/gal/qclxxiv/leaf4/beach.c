#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
object spliff, gb1, clock;
object corpse;
set_corpse(i) { corpse = i; }

yes_its_a_island_room() { return 1; }
query_whirl() { return 1; }	/* keep dragon and ianimals on island */

TWO_EXIT( "players/qclxxiv/leaf4/t_3_18","south",
			"players/qclxxiv/island/i_5_11","north",
       	 "A small bulge of a beach.\n",
       	 "A small bulge of a beach surrounded by whirlpools. The sand looks dry.\n"+
		 "It seems the water never gets this high, at least not recently.\n", 1)

extra_reset(arg) {
    if (!spliff) {
    	spliff = clone_object("players/qclxxiv/leaf4/sspliff");
    	move_object(spliff, this_object());
    }
	"/players/qclxxiv/leaf4/grifroom"->is_tide_exit();
	PLACE_IN_THIS(clock,"players/qclxxiv/leaf4/clock");
	start_dragon();
	if (arg) return;
	items = ({ "pole", "A solidly grounded pole",
			});
}

is_tide_exit() { return 1; }

init() {
	::init();
/*	add_action("wp", "north");*/
	add_action("wp", "northeast");
	add_action("wp", "northwest");
	add_action("wp", "east");
	add_action("wp", "west");
	add_action("wp", "southeast");
	add_action("wp", "southwest");
}

wp(arg) {
	this_player()->move_player( "sucked in by whirlpool#",
									"/players/qclxxiv/leaf4/wp_18" );
	return 1;
}

start_dragon() {
	object dragon, now, where;
	int x, y;
	if (corpse && environment(corpse) && environment(corpse)->query_qisland())
		return;
	dragon = find_living("islanddragon");
	if (!dragon) dragon = clone_object("/players/qclxxiv/island/dragon");
	now = environment(dragon);
	if (!now || !now->query_qisland()) {
		x = random(6)+3;
		y = random(6)+3;
		where = "/players/qclxxiv/island/i_"+x+"_"+y;
		where->query_qisland();
		move_object(dragon, where);
		dragon->run_away();	
	}
}
