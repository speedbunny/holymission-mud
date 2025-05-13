#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"

	void reset(int arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "In the river."; 
	long_desc =
		  "Here the river is narrow and the stream is very fast. You must swim faster\n"
		+ "if you want to swim successfuly through this dangerous part of the river.\n"
		+ "The water is darker here than in the other parts of the river. There are\n"
		+ "probably high reefs under the surface. The riverfloor is covered with big\n" 
		+ "and small boulders. River further continues to the south and northwest.\n";
	smell = "You are under water. You smell nothing.";
	dest_dir =
	      ({CESTA+"river2","south",
	        CESTA+"river4","northwest"});
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

