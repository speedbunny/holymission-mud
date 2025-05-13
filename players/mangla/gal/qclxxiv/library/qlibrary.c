#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
object s1, s2, s3, s4, s5, librarian, table;

query_qnewbie() { return 1; }
query_newbiehint() { 
	return "If the index is on the table, get it with: get index from table.\n";
}

extra_reset(arg) {
	object scroll;
	if (!librarian) {
	PLACE_IN_THIS(librarian,HOME+"library/librarian");
	}
	if (!s1) {
	PLACE_IN_THIS(s1,HOME+"library/shelf1");
	s1->set_color("red");
	}
	if (!s2) {
	PLACE_IN_THIS(s2,HOME+"library/shelf2");
	s2->set_color("yellow");
	}
	if (!s3) {
	PLACE_IN_THIS(s3,HOME+"library/shelf3");
	s3->set_color("green");
	}
/*
	if (!present("scroll",s3)) {
		scroll = clone_object("/players/kasgaroth/obj/scroll");
		if (scroll) move_object(scroll,s3);
	}
*/
	if (!s4) {
	PLACE_IN_THIS(s4,HOME+"library/shelf4");
	s4->set_color("blue");
	}
	if (!s5) {
	PLACE_IN_THIS(s5,HOME+"library/shelf5");
	s5->set_color("purple");
	}
	PLACE_IN_THIS(table,HOME+"library/table");
	if (arg) return;
	property = ({ "no_fight","no_steal","no_sneak","has_fire" });
    set_nodig(1);
	items = ({		"shelves", 
"Shelves carrying books. The shelves as well as the books seem to obey some\n"
+"kind of color code, but you can't understand the system",
					"books",
"Books carried by shelves. The books as well as the shelves seem to obey some\n"
+"kind of color code, but you can't understand the system",
					"list", "A list of books that are out on loan",
					"board", "A board with library rules",
					"desk", "A small wooden desk",
					"chair", "A wooden chair",
					"chairs", "Wooden chair all around",
					"wall", "A white-painted wall",
					"walls", "White-painted walls",
				"lanthorns", 
"Shining copper oil-burning lanthorns, spreading their yellowish light",
			});
}

light_text(str) {
	write("You light the "+str+" on one of the lanthorns.\n");
	say(this_player()->query_name()+" lights a "+str+",\n"
			+ "on one of the lanthorns.\n");
	tell_room(this_object(), "Librarian says: be careful with fire in here, "
		+this_player()->query_name()+"\n" );
}

do_get( arg ) {
	if (!arg) return 0;
	switch (arg) {
		case "list" : 
		case "board" :
		case "desk":
		case "chair":
			write("The librarian looks at you in a threatening way...\n"
				+"You decide not to take it.\n"); break;
		case "table": write("It is far too heavy.\n"); break;
		case "wall": write("Now how do you plan to carry that?\n"); break;
		case "lanthorns" :
			say(this_player()->query_name()
				+" tries to steal the lanthorns, but can't loosen them.\n");
			write("They have been solidly mounted to the walls.\n");
			break;
		case "index":
			if (!present("index") && present("table")) {
				if (present("index", present("table"))) {
					write("The index is on the table.\n");
					return 1;
				}
			}
			return 0;
		case "book":
			if (!present("book") && present("shelf")) {
				write("Maybe try to  get book from shelf?\n");
				return 1;
			}
			return 0;
		default: return 0;
	}
	return 1;
}

ONE_EXIT("/players/qclxxiv/entrance","south",
	      "The library of the Q castle",
	 "The library of the Q castle. Shelves are all around. A librarian is\n"
	+"sitting behind a desk in a corner. A list is on the wall, and also a\n"
	+"board with library rules. Lanthorns are lightening the room.\n", 1)

its_qlibrary() { return 1; }

init() {
   ::init();
	add_action("south","south");
	add_action("putbook","put");
	add_action("dropbook","drop");
	add_action("destbook","destruct");
	add_action("destbook","dest");
	add_action( "do_get", "get" );
    add_action("read_list", "read");
    add_action("sit", "sit");
	add_action("standup", "stand");
}

dropbook(arg) {
	string which;
	if (arg=="book" || sscanf(arg,"%s book",which)==1) {
		tell_room(this_object(),
			"Librarian says: Please put the books back on their shelves"
					+", "+this_player()->query_name()+"\n");
		if (which = present(arg,this_player())) {
			transfer(which,this_object());
			write("Ok.\n");
		}
		return 1;
	}
	if (arg=="index" && (which = present(arg,this_player())) ) {
		transfer(which,this_object());
		write("Ok.\n");
		return 1;
	}
	if (which = present(arg,this_player())) {
		transfer(which,this_object());
		write("Ok.\n");
		tell_room(this_object(),"Librarian frowns.\n");
		tell_room(this_object(),
			"Librarian says: Do not drop all kinds of rubbish here please"
					+", "+this_player()->query_name()+"\n");
		return 1;
	}
	return 0;
}

putbook(arg) {
	string which, what;
	if (sscanf(arg,"book in %s",what)==1
		|| sscanf(arg,"index in %s",what)==1
		|| sscanf(arg,"%s book in %s",which,what)==2 ) {
		tell_room(this_object(),
			"Librarian says: Please do not put books in your "
					+what+", "+this_player()->query_name()+"\n");
		return 1;
	}
	return 0;
}

south(arg) {
	if (present("qlib_book",this_player())) {
		tell_room(this_object(), 
				"Librarian says: Please do not take books with you "
				+this_player()->query_name()+"\n");
		return 1;
	}
	return 0;
}

exit(obj) {
	object o;
	while (o = present("qlib_book",obj)) {
		move_object(o, this_object());
		tell_object(obj,"You drop a book.\n");
	}
}

destbook(arg) {
	string which;
	if (arg=="book" || sscanf(arg,"%s book",which)==1) {
		tell_room(this_object(),
			"Librarian says: That is not very neat of you"
					+", "+this_player()->query_name()+"\n");
		tell_room(this_object(),
	"Librarian says: I had not expected that from you. You disappoint me.\n");
	}
	return 0;
}

read_list(str) {
    if (str=="list") { 
        write("On loan: (book                - name, address) \n");
		write("Book of Paradox               - Q174\n");
		write("On distant killing            - Gruelbert, shelter\n");
		write("Diamonds and where to dig     - Khnurt, mushroom\n");
		write("Maps of the leaf              - Errol, shanty in hills\n");
		write("How to become a wiz in 1 week - Joe, barn\n");
		write("On the creation of quests     - Q174\n");
		write("Monster Almanak               - Jack, shed\n");
		write("Experience the easy way       - Dirthead, shackle\n");
    	return 1;
	}
    if (str=="board") { 
        write("Library rules:\n");
		write(
	"-Keep silence! Do not talk, fight, or otherwise disturb the readers!\n");
		write("-Treat the books with care!\n");
		write("-Keep the place tidy!\n");
		write("-Place books back on their proper locations!\n");
		write("-No books can be lend out to guests from outside this area!\n");
    	return 1;
	}
	return 0;  
}

try_attack(tp) {
	if (tp==librarian) return 0;
	tell_object(tp,"You get kicked out by the librarian.\n");
	tp->move_player("kicked","/players/qclxxiv/entrance");	
	tell_room(this_object(),tp->query_name() 
						+" gets kicked out by the librarian.\n");
}

sit(str) {
    if (str=="on chair") { 
        write("You sit down on a wooden chair.\n");
		say(this_player()->query_name()+" seats "+ 
				this_player()->query_objective()
								+"self on a chair.\n", this_player());
    	return 1;
	}
	write("Sit on what?\n");
	return 1;
}

standup(arg) {
	if (arg=="up") {
		write("Ok.\n");
		say(this_player()->query_name()+" stands up.\n");
		return 1;
	}
	return 0;
}

