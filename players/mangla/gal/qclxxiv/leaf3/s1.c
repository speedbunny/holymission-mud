#include "/players/qclxxiv/leaf3/leaf3room.h"

TWO_EXIT( HOME+"circular/circ3","southwest",  HOME+"leaf3/s2","northeast",
"A small street", 
"A small street running northeast towards a hamlet. A street-sign on a pole.\n"
+"To both sides a steep dyke stretches forth enclosing the street and the\n"
+"hamlet as far as the sight reaches.\n",
1)

towadden() { return "southwest"; }

init() {
	::init();
	add_action( "do_get", "get" );
	add_action( "tocircular", "southwest" );
	add_action("to_d1", "west");
	add_action("to_d27", "south");
	add_action("read", "read");
}

read(arg) {
	if (arg=="sign"||arg=="street-sign") {
		write(
"A blue sign with white letters reading: 'Dyke street' and: '>;:' =.{''.'.\n");
		return 1;
	}
	return 0;
}

extra_reset(arg) {
	if (arg) return;
    set_nodig(1);
	items = ({
		"dyke", "A steep gray old dyke",
		"street" , "Just a bumpy old bricked street",
		"sign", 
"A blue sign with white letters reading: 'Dyke street' and: '>;:' =.{''.'",
		"street-sign", 
"A blue sign with white letters reading: 'Dyke street' and: '>;:' =.{''.'",
		"pole", "Just an ordinary old wooden pole. While looking at it you\n"
+"become aware of the obscure little paths running upward the dykes to the\n"
+"west and south",
		"hamlet", 
"An small, decayed, seemingly fishing-, village", 
	});
}

do_get( arg ) {
	if (!arg) return 0;
	switch (arg) {
		case "hamlet" :
		case "street" : write("How do you plan to carry that?\n"); break;
		case "street-sign" : write("It is mounted too firmly.\n"); break;
		case "pole":write("It has been drilled deep into the ground.\n"); break;
		default: return 0;
	}
	return 1;
}

tocircular(arg) {
	write(
"You have a strange feeling...and suddenly are inside the giant leaf again.\n");
	move("southwest");
	return 1;
}

to_d1(arg) {
	this_player()->move_player("west", "players/qclxxiv/leaf3/d01");
	return 1;
}
to_d27(arg) {
	this_player()->move_player("south", "players/qclxxiv/leaf3/d27");
	return 1;
}
