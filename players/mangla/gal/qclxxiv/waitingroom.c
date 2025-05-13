#include "naming.h"
#include "/players/qclxxiv/myroom.h"
object spliff, fishtea;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

query_qnewbie() { return 1; }
query_newbiehint() { 
	return "Look at all things in the rooms if you don't want to\n"
		+"miss vital information... Not that all things are of importance,\n"
		+"but how can you know in advance...\n";
}

extra_reset(arg) {
/*
    if (!spliff) {
    	spliff = clone_object("players/qclxxiv/spliff");
    	move_object(spliff, this_object());
    }
*/
    if (!fishtea || environment(fishtea)!=this_object()) {
    	fishtea = clone_object("players/qclxxiv/fishtea");
    	move_object(fishtea, this_object());
    }
	if (arg) return;
    set_nodig(1);
	items = ({ 
			"couch", "A comfortable couch, inviting you to sit on it",
			"couches", "Comfortable couches, inviting you to sit on them",
			"table", "A low, round table carrying an ashtray and some cups",
			"wall", "Just old dark stone wall",
			"walls", "Old dark stone walls",
			"ashtray", "A big white ashtray with some ashes and stubs",
			"ashes","Just regular ishen ashes",
			"stubs","Just regular spliff stubs",
			"cups", "seems like they just love dem fishtea around here",
				"large shield",
"A large shield, featuring a blue cross dividing it into four quadrants. In\n"
+"them: a seven-fingered leaf, a lion, a six-pointed star, and a book",
				"shield",
"A large shield, featuring a blue cross dividing it into four quadrants. In\n"
+"them: a seven-fingered leaf, a lion, a six-pointed star, and a book",
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

TWO_EXIT( /* "players/qclxxiv/workroom","west", */
          /*    "players/qclxxiv/library","south", */
			"players/qclxxiv/stem/stem1","north",
			"players/qclxxiv/entrance","east",
"Inside the roots of a giant leaf, serving as "+NAME+"'s waiting room",
"Inside the roots of a giant leaf, serving as "+NAME+"'s waiting room.\n"+
"There are comfortable couches and a table in the midst. Lanthorns spread\n"
+"their light. To the north it seems one can enter the leaf's stem......\n"+
/*"A strange blue light is shining in from the west and south.\n"+*/
"On top of a bricked up doorway to the west is painted: 'Negus Qclxxiv' and\n"+
"in some exotic alphabet: '+'}|=- *u!oo&m'. Next to it, a large shield is\n"+
"hanging on the wall.\n" ,1)

init() {
	object I;
	::init();
    add_action("sit", "sit");
    add_action("west", "west");
    add_action("south", "south");
	add_action("standup", "stand");
	add_action("do_get", "get" );
	if (I = find_player("qclxxiv")) {
		if (I!=this_player()) {	
			tell_object(I, ">>>>>>>>>>>>> "+
				this_player()->query_name()+" entered the waitingroom.\n");
		}
	}
}

west(str) {
	if (this_player()->query_level()>=30) {
		write("You magically pass through the bricked up doorway.\n");
		say( this_player()->query_name()
			+" magically passes through the bricked up doorway.\n");
    	this_player()->move_player( "through doorway", 
				"/players/qclxxiv/workroom" );
		return 1;
	}
	write("You bang your head against the bricked up doorway.\n");
	say( this_player()->query_name()
		+" bangs against the bricked up doorway headwise.\n");
	return 1;
}

south(str) {
	object ob;
	ob = first_inventory(this_player());
	while(ob) {
		if (call_other(ob,"id","dreadlocks")) {
			write("You magically pass through the southern wall.\n");
			say( this_player()->query_name()
				+" magically passes through the southern wall.\n");
    		this_player()->move_player( "through wall", 
					"/players/qclxxiv/library" );
			return 1;
		}
		ob = next_inventory(ob);
	}
	write("You bang your head against the through the southern wall.\n");
	say( this_player()->query_name()
		+" bangs against the southern wall headwise.\n");
	return 1;
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

sit(str) {
    if (str=="on couch") { 
        write("You sit down on the comfortable couch and feel your "
				+"body relaxing\n");
		say(this_player()->query_name()+" seats "+ 
				this_player()->query_objective()
								+"self on a couch.\n", this_player());
    	return 1;
	}
	write("Sit on what?\n");
	return 1;
}

standup(arg) {
	if (arg=="up") {
		say(this_player()->query_name()+" stands up.\n");
		return 1;
	}
	return 0;
}

