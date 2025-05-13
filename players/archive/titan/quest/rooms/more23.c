#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"

	void reset(int arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "In the sea gulf.";
	long_desc = "You are somewhere in the shallow gulf. Water is pleasant warm and\n"
		    "and blue like a sky. The sea floor is sandly and covered with\n"
		    "many shells. This part of gulf is full of life. To the southeast\n"
		    "begins deep ocean and to the west you can see steep cliffs\n"
		    "belonging to the island.\n";

	items = ({"shells","There are many shells. Maybe you can try search it",
		  "cliffs","Steep cliffs belonging to the island of Blur"});

	dest_dir =
	      ({CESTA+"more18","northwest",
	        CESTA+"more24","east",
		CESTA+"more28","south",
		CESTA+"more19","north"});
	}
	init() {
	::init();

        while(present("torch",this_player())) {
	object fakla,mokra;
	fakla=present("torch",this_player());
	destruct(fakla);
	mokra=clone_object("players/titan/quest/items/wet_torch");
	transfer(mokra,this_player());
}}
