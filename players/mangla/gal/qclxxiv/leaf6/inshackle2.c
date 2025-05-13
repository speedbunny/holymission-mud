#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
int found;

extra_reset(arg) {
	found = 0;
	if (arg) return;
	items = ({
				"shelf", "Just a dirty shelf. Maybe you should search it",
				"shelves","Ordinary dirty shelves. One draws your attention",
				"walls","The walls are as dirty as anything around here",
			});
}

ONE_EXIT(  "players/qclxxiv/leaf6/inshackle1","south", 
"Inside a dingy dark shackle",
"Inside a dingy dark shackle. Some dirty shelves are along the walls. You\n"+
"still wonder what has been stored here. Right now the place looks empty.\n",0)

init() {
	::init();
	add_action("search", "search");
}

search(arg) {
	object book;
	if (arg=="shelf") {
		say(this_player()->query_name()+" searches a shelf.\n");
		if ("/players/qclxxiv/qquest/qmast"->lock_name2key( 0,
					this_player()->query_real_name() ) == 4 ) {
			if (found) 
				write(
"Looking close at the shelf you can see a rectangular object has been there.\n"
+"It may well have been a book. However someone must have been before you.\n");
			else {
				write("You find a book.\n");
				PLACE_IN_THIS(book, HOME+"library/book");
				book->set_color("yellow");
				book->set_covertext("Qxcix - Experience the easy way.\n"); 
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
