/* entrance.c entrance room of Qclxxiv's castle.  */
#include "/players/qclxxiv/naming.h"  /* TITLE + NAME */
#include "/players/qclxxiv/castle.loc"
/* #include "/room/std.h" */
#include "/players/qclxxiv/myroom.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
object jackpot, q173;

query_qnewbie() { return 1; }
query_newbiehint() { 
	return "Listen some time to Q173 if he is here, various creatures\n"
			+"in this region may give important information...\n"
			+"By the way, east is a shop, and east thereof is Rasta's\n"
			+"Ital Bar, surely safe, but no longer in the Qs' area.\n";
}

extra_reset(arg) { 
	object ob,newbieguide;
	if (find_object("/room/hump") 
		&& !present("lump",find_object("/room/hump"))) {
		newbieguide = clone_object("/players/qclxxiv/qquest/qonyx");
		if (newbieguide) move_object(newbieguide,"/room/hump");
	}
	if (!jackpot) {
		jackpot = clone_object("players/qclxxiv/jackpot");
		move_object(jackpot, this_object());
	}
	if (!q173) {
		q173 = clone_object("players/qclxxiv/q173");
		move_object(q173, this_object());
	}
	if (arg) return;
/*
    ob = clone_object("obj/quest_obj");
    call_other(ob, "set_name", "island dragon");
    call_other(ob, "set_hint",
		"Go to the seven-fingered leaf and keep your eyes and ears open.\n");
    move_object(ob, "room/quest_room");
*/
	tell_room(this_object(),
			"A goblin appears and wishes you an extra warm welcome....\n"); 
    set_nodig(1);
	items = ({ "gates", "They are set ajar",
				"doors", "Large oaken doors",
				"door", "A large oaken door",
				"warning", "A warning written on a red, gold, and green board",
				"sign", "A wooden sign, painted red, gold, and green",
				"large shield",
"A large shield, featuring a blue cross dividing it into four quadrants. In\n"
+"them: a seven-fingered leaf, a lion, a book, and a feather in an ink-well",
				"shield",
"A large shield, featuring a blue cross dividing it into four quadrants. In\n"
+"them: a seven-fingered leaf, a lion, a book, and a feather in an ink-well",
				"walls", "Old dark stone walls",
				"wall", "An old dark stone wall",
				"lanthorns", 
"Shining copper oil-burning lanthorns, spreading their yellowish light",
			});
	property=({ "has_fire" });
}

light_text(str) {
	write("You light the "+str+" on one of the lanthorns.\n");
	say(this_player()->query_name()+" lights a "+str+",\n"
			+ "on one of the lanthorns.\n");
}

FOUR_EXIT( DEST ,"south",
           "players/qclxxiv/waitingroom","west",
           "players/qclxxiv/myshop","east",
		   "players/qclxxiv/library/qlibrary", "north",
"A large entry hall with a sign and a warning on the northern wall",
"A large entry hall with a sign and a red, gold and green warning on the\n"+
"northern wall. Above an entrance to the north letters are painted: 'Library'\n"
+"and in an exotic alphabet: '!&<{-{;'. Next to it, a large shield is hanging.\n"
+"Lanthorns spread their yellowish light. Above an entrance to the east: `Luxury\n"+
"shop' and `!|o|{; =_,('. To the south, the castle's main gates are set ajar.\n"
/* There are large oaken doors to the west and\n" +"east, both opened. */
/*
+"There is a temporary pamphlet, waiting to be read.\n"
*/
, 1)

/* extra_init() { */
init() {
	object I;
	::init();
    add_action("read_sign", "read");
	add_action("do_get", "get" );
	if (I = find_player("qclxxiv")) {
		if (I!=this_player()) {	
			tell_object(I, ">>>>>>>>>>>>> "+
				this_player()->query_name()+" entered the entrance.\n");
		}
	}
}

do_get(arg) {
	if (arg=="shield" && present("shield")) {
		if (transfer(present("shield"),this_player())!=0)
			write("You cannot carry any more.\n" );
		else {
			write("Ok.\n");
			say(this_player()->query_name()+" takes a shield.\n",
				this_player() );
		}
		return 1;
	}
	else if (arg=="lanthorns") {
		say(this_player()->query_name()
		+" tries to steal the lanthorns, but can't loosen them.\n");
		write("They have been solidly mounted to the walls.\n");
		return 1;
	}
	return 0;
}

read_sign(str) {
    if (str=="sign") { 
        write("\n");
    	write( "Welcome guest if thou hast honourable intentions. "+
				"Woe to thee otherwise....\n");
		write( "n'!u,#' }|'=. &) ._,| _-=. _,+,|{-<!' &+.'+.&,+=. "+
				"n,' ., ._'' ,._'{n&='....\n");
    	return 1;
	}
    if (str=="warning") { 
        write("\n");
    	write( "Warning, you entered Negus Qclxxiv's territory.\n"
			+"It is wrapped up in time-space so it could just be in any\n"
			+"solar system, but don't try to fit in into the village map.\n");
    	return 1;
	}
/*
    if (str=="pamphlet") { 
        write("\n");
    	write( "Due to some library changes in my recent 4 week holiday\n"
			+"some things in the region cause errors or dont behave well.\n"
			+"This makes that the very last parts of the quest cannot\n"
			+"even been done yet.   I'll try to change this asap!\n"
			+"However, many interesting monsters and things can be found\n"
			+"and the big part of the quest can be done already.\n"
			+"AND having done it, it is possible to do the final part later!\n"
			+"Please report all errors etc using the proper bug, typo, etc.\n"
			+"commands.\n\n"
+"Sorry for the inconveniences,  Qclxxiv (aka q174)\n"
			);
    	return 1;
	}
*/
	return 0;  
}

