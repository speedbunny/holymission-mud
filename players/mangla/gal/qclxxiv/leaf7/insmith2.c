#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
object dwarfsmith;

extra_reset(arg) {
	if (arg) return;
	PLACE_IN_THIS(dwarfsmith,"/players/qclxxiv/leaf7/dwarfsmith" )

	items = ({
				"walls", "Just ordinary mushroom walls",
				"fire", "A rather hot, neatly kindled fire",
				"anvil", "A very old and very heavy looking anvil",
			});
}

ONE_EXIT( "players/qclxxiv/leaf7/insmith1","north", 
"Inside a mushroom",
"Inside a mushroom. You have to bend not to bump your head. To the north the\n"+
"room continues. A fire is in the center, and an anvil is next to it.\n",1)

init() {
	::init();
	add_action("do_get", "get" );
}


do_get(arg) {
	if (arg=="fire" ) {
		write("You burn your hands.\n" );
		return 1;
	}
	else if (arg=="anvil") {
		say(this_player()->query_name()
		+" tries to take the anvil, but can't lift it from the floor.\n");
		write("You can't take it, it's way too heavy.\n");
		return 1;
	}
	return 0;
}

