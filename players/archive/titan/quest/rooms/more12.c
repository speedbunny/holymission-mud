#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"

	void reset(int arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "In the sea gulf";
	long_desc = "This part of the gulf is not so pleasant as other parts of the sea gulf, \n"
                    "because water is colder and darker here. You have a big problems \n"
		    "to see sea floor although you can see somewhere on the sea floor \n"
		    "small shells. To the east begin deep ocean.\n";

	items = ({
		"shells","There are many shells on the sea floor. Maybe you can search it",
		"water","Water is dark and cold"});

	dest_dir =
	      ({CESTA+"more11","west",
	        CESTA+"more20","southeast",
		CESTA+"more19","south",
		CESTA+"more6","north"});
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
