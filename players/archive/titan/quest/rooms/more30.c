#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"
int counter;

	void reset(int arg) {
	::reset(arg);
	counter=1;
	if(arg) return;

	set_light(1);
	short_desc = "In the sea gulf";
	long_desc = "What the hell are you looking at (ty vymrdanec).\n";

	dest_dir =
	      ({CESTA+"more29","west",
	        CESTA+"more31","east",
		CESTA+"more35","southeast",
		CESTA+"more26","north"});
	}
	init() {
	::init();
	add_action("search","search");
}
	search(str) {
	if(!str) {
	notify_fail("Search what ?");
	return 0;
}
	if(str=="shells"&&present("nic",this_player())&&counter==1) {
	write("You find small pearl.\n");
	move_object(clone_object("players/titan/quest/items/pearl"),this_player());
	counter=1+1;
	return 1;
}
	if(str=="shells"&&present("nic",this_player())&&counter>1) {
	write("You find nothing.\n");
	return 1;
}}
