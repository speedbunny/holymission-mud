#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"
int counter,i;

	void reset(int arg) {
	if(!present("cod",this_object())) {
	(i=0);
{
	while(i<5) {
	move_object(clone_object("players/titan/quest/monsters/cod"),this_object());
	(i=i+1);
}}}
	::reset(arg);
	counter=1;
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
	      ({CESTA+"more35","north",
	        CESTA+"more43","east"});
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
