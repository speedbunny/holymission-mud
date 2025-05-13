#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"

	void reset(int arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "In the sea gulf";
	long_desc =
		"This is the shallow part of the sea. The water is clear as crystal and\n"
		"pleasant warm. The sea floor is covered with yellow sand and shells.\n"
		"When you stand up on sea floor you rise to the surface. Maybe you can try it.\n";
	dest_dir =
	      ({CESTA+"more13","southwest",
	        CESTA+"more8","east",
		CESTA+"more14","south",
		CESTA+"more2","northeast"});

	items = ({
		"mussels","You see many kind of mussels",
		"sand","Yellow sand",
		"water","It is warm and clear"});
}
	init() {
	::init();
	add_action("stand","stand");
}
	stand(str) {
	if(str=="up"||!str) {
	write("Your head rises up to surface.\n");
	say(this_player()->query_name()+" stands up and leaves sea.\n");
	this_player()->move_player("#players/titan/quest/rooms/sea1");
	return 1;
}
	else
	return 0;
}
