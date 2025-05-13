#include "../seaworld.h"

#define CESTA "/players/titan/quest/rooms/"
#define TP this_player()

	void reset(int arg) {
	::reset(arg);

	if(!present("medusa",this_object())||!present("statue",this_object())) {
	move_object(clone_object("players/titan/quest/monsters/medusa"),this_object());
}
	if(arg) return;

	set_light(1);
	short_desc = "In the sea cave.";
	long_desc = "This dark sea cave is very gloom. Water is terribly cold and dark.\n"
		    "Only one source of light is lighting up here. It is tiny opening on\n"
		    "the top of cave. You have strange feeling that you have entered\n"
		    "to the cave of last day. You quickly take your bones and get out of here.\n";

	items = ({"opening","Small opening on the top of cave. Maybe you can go up"});

	dest_dir =
		({CESTA+"more32","southwest"});
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
	add_action("pass","up");
}
	pass() {
	if(present("medusa",this_object())) {
		write("Medusa bars your way.\n");
		return 1;
}
		else {
		write("You have passed to the island.\n");
		TP->move_player("\b\b\b\b\b\b\bpassed through opening#/players/titan/quest/rooms/island");
		return 1;
}}
