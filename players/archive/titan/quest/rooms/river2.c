#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"

	void reset(int arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "In the river."; 
	long_desc = 
		  "You are swiming in a shallow river. To both sides of the river you see\n"
		+ "smaller or bigger affluents. The riverfloor is stoney. The river continues\n"
		+ "to the north and south.\n";
	smell = "You are under water, you smell nothing.";
	items = ({
		"surface","Stone surface",
		"affluents","You see many affluents"});
	dest_dir =
	      ({CESTA+"river1","south",
	        CESTA+"river3","north"});
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
