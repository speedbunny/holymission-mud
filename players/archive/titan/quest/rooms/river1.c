#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"

	void reset(int arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "Mount of the river.";
	long_desc =
		  "In this place the river flows into the sea. The water is colder than the\n"
		+ "sea and it is fresh. There appears to be slow stream and you have to\n" 
		+ "swim faster. Under you is a stone riverfloor. The river continues to the\n"
		+ "north and flows to sea to the south.\n";
	smell = "You are under water, you smell nothing.";
	items = ({
		"riverfloor","You see large quanties of stones"});
	dest_dir =
	      ({CESTA+"more1","southwest",
	        CESTA+"river2","north"});
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
