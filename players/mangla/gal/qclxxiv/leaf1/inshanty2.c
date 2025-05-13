#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
int found;

extra_reset(arg) {
	found = 0;
	if (arg) return;
	items = ({
				"shelf", "Just a wooden shelf. Maybe you should search it",
				"shelves","A few wooden shelves. One catches your eye",
			"walls","They may once have been painted, but are now peeled off",
			});
}

ONE_EXIT(  "players/qclxxiv/leaf1/inshanty1","southeast", 
"Inside a small peeled off shanty",
"Inside a small peeled off shanty. Away from the door it's even darker here.\n"+
"The place looks empty, apart for some shelves, though from the scarce\n"+
"dust one would guess the place was in use at least not too long ago.\n",0)

init() {
	::init();
	add_action("search", "search");
}

search(arg) {
	object book;
	if (arg=="shelf") {
		say(this_player()->query_name()+" searches a shelf.\n");
		if ("/players/qclxxiv/qquest/qmast"->lock_name2key( 0,
					this_player()->query_real_name() ) == 0 ) {
			if (found) 
				write(
"Looking close at the shelf you can see a rectangular object has been there.\n"
+"It may well have been a book. However someone must have been before you.\n");
			else {
				write("You find a book.\n");
				PLACE_IN_THIS(book, HOME+"library/book");
				book->set_color("Grey");
				book->set_covertext("Qxxx - Maps of the leaf.\n"); 
				book->set_pages( ({
"The maps are in an ancient style and you can't understand them.\n",
"The maps are in an ancient style and you can't understand them.\n",
"You can't understand it.\n", "Unreadable to you.\n", "Unreadable to you.\n",
					}) );
				book->set_openfind(HOME+"qquest/q1note");
				book->set_open2dest(30);
				found = 1;
			} 
		}
		else write("You find nothing.\n");
		return 1;
	}
	return 0;
}
