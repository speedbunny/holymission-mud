#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"
int counter;

	void reset(int arg) {
	::reset(arg);
	counter=1;
	if(arg) return;

	set_light(1);
	short_desc = "In the sea gulf.";
	long_desc = "You are somewhere in the shallow gulf. Water is pleasant warm and\n"
		    "and blue like a sky. The sea floor is sandly and covered with\n"
		    "many shells. To the north you can see steep cliffs belonging\n"
		    "to the island.\n";

	items = ({"shells","There are many shells. Maybe you can try search it",
		  "cliffs","Steep cliffs belonging to the island of Blur"});

	dest_dir =
	      ({CESTA+"more37","west",
	        CESTA+"more40","east",
		CESTA+"more45","south"});
	}
	init() {
	::init();
        while(present("torch",this_player())) {
	object fakla,mokra;
	fakla=present("torch",this_player());
	destruct(fakla);
	mokra=clone_object("players/titan/quest/items/wet_torch");
	transfer(mokra,this_player());
}
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
