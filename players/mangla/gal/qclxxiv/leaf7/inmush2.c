#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
object dwarfchamp;
int found;

extra_reset(arg) {
	found = 0;
	if (arg) return;
	PLACE_IN_THIS(dwarfchamp,"/players/qclxxiv/leaf7/dwarfchamp" )

	items = ({
				"shelf", "Just an ordinary shelf. Maybe you should search it",
				"shelves","Ordinary wooden shelves. One draws your attention",
				"walls", "Just ordinary mushroom walls",
			});
}

ONE_EXIT( "players/qclxxiv/leaf7/inmush1","west", 
"Inside a mushroom",
"Inside a mushroom. You have to bend not to bump your head. To the west the\n"+
"room continues. Shelves cover the wall here.\n",1)

init() {
	::init();
	add_action("search", "search");
}

search(arg) {
	object book;
	if (arg=="shelf") {
		say(this_player()->query_name()+" searches a shelf.\n");
		if ("/players/qclxxiv/qquest/qmast"->lock_name2key( 0,
					this_player()->query_real_name() ) == 5 ) {
			if (found) 
				write(
"Looking close at the shelf you can see a rectangular object has been there.\n"
+"It may well have been a book. However someone must have been before you.\n");
			else {
				write("You find a book.\n");
				PLACE_IN_THIS(book, HOME+"library/book");
				book->set_color("blue");
				book->set_covertext("Qxlviii - Diamonds and where to dig.\n"); 
				book->set_pages( ({
"The texts are in an ancient language and are unreadable to you.\n",
"The texts are in an ancient language and are unreadable to you.\n",
"Unreadable to you.\n", "Unreadable to you.\n", "Unreadable to you.\n",
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
