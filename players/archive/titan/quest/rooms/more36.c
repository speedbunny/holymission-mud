#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"
#define TP this_player()

	void reset(int arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "In the sea gulf";
	long_desc = "What the hell are you looking at (ty vymrdanec).\n";

	dest_dir =
	      ({CESTA+"more35","west",
	        CESTA+"more37","east",
		CESTA+"more43","south",
		CESTA+"more32","north"});
	}
	init() {
	::init();
	add_action("vojdi","enter");
}
	vojdi(str) {
	int i;
	i=TP->query_str()+TP->query_dex()+TP->query_con();
	if(str=="shipwreck") {
		if(i<45) {
		write("It is too deep for you.\n");
		return 1;
}
		else {
		write("You have entered to the shipwreck.\n");
		TP->move_player("ship1#/players/titan/quest/rooms/ship1");
		return 1;
}}
	return 1;
}
