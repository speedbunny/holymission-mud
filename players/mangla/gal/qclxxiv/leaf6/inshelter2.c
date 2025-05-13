#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
int found;

extra_reset(arg) {
	found = 0;
	if (arg) return;
	items = ({
				"shelf", "A rotting wooden shelf. Maybe you should search it",
				"shelves","Rotting wooden shelves. One catches the eye",
				"walls","Mouldy walls which are rotten through and through",
			});
}

ONE_EXIT(  "players/qclxxiv/leaf6/inshelter1","north", 
"Inside a dark mouldy shelter",
"Inside a dark mouldy shelter. The musty stench of rotting wood is almost\n"+
"tangible. Apart for some rotting wooden shelves the place is empty.\n",0)

init() {
	::init();
	add_action("search", "search");
}

search(arg) {
	object book;
	if (arg=="shelf") {
		say(this_player()->query_name()+" searches a shelf.\n");
		if ("/players/qclxxiv/qquest/qmast"->lock_name2key( 0,
					this_player()->query_real_name() ) == 3 ) {
			if (found) 
				write(
"Looking close at the shelf you can see a rectangular object has been there.\n"
+"It may well have been a book. However someone must have been before you.\n");
			else {
				write("You find a book.\n");
				PLACE_IN_THIS(book, HOME+"library/book");
				book->set_color("black");
				book->set_covertext("Qlv - On distant killing.\n"); 
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
