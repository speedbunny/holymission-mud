#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"
int counter;

	void reset(int arg) {
	::reset(arg);
	counter=1;
	if(arg) return;

	set_light(1);
	short_desc = "In the sea gulf";
	long_desc =
		  "In this part of sea is water pleasant warm and very clear. Sea floor \n"
		+ "goes slowly down. It is covered with sand and shells. But sometimes \n"
		+ "appears rocks scattered on sea floor.\n";

	smell = "You are under water. You smell nothing";
	items = ({
		"water","Water is transparent and pleasant warm",
		"sea floor","Sea floor is covered with sand and large quanties of shells", 
		"floor","Sea floor is covered with sand and large quanties shells",
		"shells","There are much shells with different origin",
		"rocks","Big and heavy rocks probably falls down from peaks standing around",
		"sand","It looks like gold"});

	dest_dir =
	      ({CESTA+"more8","west",
	        CESTA+"more10","east",
		CESTA+"more16","south",
		CESTA+"more3","north"});
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
