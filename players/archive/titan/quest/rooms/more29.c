#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"

	void reset(int arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "In the sea gulf.";
	long_desc = "This is dark corner of the sea gulf. The sun's rays very hard \n"
		    "penetrate among high mounts and dark water. There are quanties \n"
		    "of shells lying on the sea floor. To the south and to the west \n"
		    "are steep cliffs.\n";

	items = ({"shells","You see many shells. Maybe you can search it",
		  "cliffs","Cliffs block your way to the south and west"});

	dest_dir =
	      ({CESTA+"more25","north",
	        CESTA+"more30","east"});
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
