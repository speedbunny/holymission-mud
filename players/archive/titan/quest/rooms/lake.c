#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"

	void reset(int arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "In the small lake."; 
	long_desc = "What the hell are you looking at (ty vymrdanec).\n";

	dest_dir =
	      ({CESTA+"river6","northeast",
		CESTA+"nixier","out"});
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
