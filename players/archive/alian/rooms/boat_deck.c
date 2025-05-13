inherit "/room/room";

void reset(int arg) {
	::init();;
	short_desc="Boat Deck";
	long_desc=
		"You are standing on the deck of a ferry. You can see\n"+
		"the main shore to the west, and an island to the east.\n"+
		"There is a cabin on the boat for when it rains and it\n"+
		"is too cold to stay out in the open. Also there is a \n"+
		"walkway, which appears to lead to the front of the boat.\n";
	}

void init() {
	add_action ("do_go","go");
	add_action ("do_go","enter");
	add_action ("exit_boat","exit");
}

int do_go(string str) {
	if ((!str) ||(str != "cabin") || (str != "walkway") || (str != "front")) {return 0;}
	switch (str) {
		case "cabin" :
			this_player()->move_object("/p/alian/rooms/boat_cabin.c");
			write(this_player()->query_name()+" enters the boat cabin\n");
			break;
		default :
			this_player()->move_object("/p/alian/rooms/boat_front.c");
			write(this_player()->query_name()+" goes to the front of the ferry\n");
			break;
		}
	return 1;
	}
