#include "naming.h"
#include "/players/qclxxiv/myroom.h"
object spliff, fishtea, keg, goat, bread;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

query_qnewbie() { return 1; }
query_newbiehint() { 
	return "Look at all things in the rooms if you don't want to\n"
		+"miss vital information... Not that all things are of importance,\n"
		+"but how can you know in advance...\n";
}

extra_reset(arg) {
	FRESH_IN_ROOM(spliff, "players/qclxxiv/spliff")
    if (!keg || environment(keg)!=this_object()) {
    	keg = clone_object("players/qclxxiv/obj/guinkeg");
    	move_object(keg, this_object());
    }
    if (!bread || environment(bread)!=this_object()) {
    	bread = clone_object("players/qclxxiv/obj/cornbread");
    	move_object(bread, this_object());
    }
    if (!goat || environment(goat)!=this_object()) {
    	goat = clone_object("players/qclxxiv/obj/goat");
    	move_object(goat, this_object());
    }
	if (arg) return;
    set_nodig(1);
	items = ({ 
			"couch", "An extra comfortable couch, inviting you to sit on it",
			"couches", "Extra comfortable couches, inviting you to sit on them",
			"table", "A large, round table carrying an ashtray and some cups",
			"wall", "Just old beautifully carved stone wall",
			"walls", "Old beautifully carved stone walls",
			"ashtray", "A big white ashtray with some ashes and stubs",
			"ashes","Just regular high-quality ishen ashes",
			"stubs","Just regular high-quality spliff stubs",
			"cups", "seems like they just love dem fishtea around here",
				"large shield",
"A large shield, featuring a blue cross dividing it into four quadrants. In\n"
+"them: a seven-fingered leaf, a lion, a six-pointed star, and a book",
				"shield",
"A large shield, featuring a blue cross dividing it into four quadrants. In\n"
+"them: a seven-fingered leaf, a lion, a six-pointed star, and a book",
				"lanthorns", 
"Shining silver oil-burning lanthorns, spreading their yellowish light",
			});
	property=({ "has_fire" });
}

light_text(str) {
	write("You light the "+str+" on one of the silver lanthorns.\n");
	say(this_player()->query_name()+" lights a "+str+",\n"
			+ "on one of the silver lanthorns.\n");
}

THREE_EXIT("players/qclxxiv/workroom","south",
			"players/qclxxiv/waitingroom","east",
			"players/nokey/centralroom", "central",
"Inside "+NAME+"'s extra special guest room",
"Inside "+NAME+"'s extra special guest room.\n"+
"There are extra comfortable couches and a large table in the midst. Silver\n"
+"lanthorns spread their extra nice light. A strange blue light is shining\n"
+"in from the south. To the east one can enter the general waitingroom.\n"
+"A large shield is hanging on the wall next to the southern entrance.\n" ,1)

init() {
	object I;
	::init();
    add_action("sit", "sit");
	add_action("standup", "stand");
	add_action("do_get", "get" );
	if (I = find_player("qclxxiv")) {
		if (I!=this_player()) {	
			tell_object(I, ">>>>>>>>>>>>> "+
				this_player()->query_name()+" entered the guestroom.\n");
		}
	}
}

do_get(arg) {
	extra_reset(100);
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
		+" tries to steal the silver lanthorns, but can't loosen them.\n");
		write("They have been solidly mounted to the walls.\n");
		return 1;
	}
	return 0;
}

sit(str) {
    if (str=="on couch") { 
        write("You sit down on the extra comfortable couch and feel your "
				+"body relaxing\n");
		say(this_player()->query_name()+" seats "+ 
				this_player()->query_objective()
				+"self on a extra comfortable couch.\n", this_player());
    	return 1;
	}
	write("Sit on what?\n");
	return 1;
}

standup(arg) {
	if (arg=="up") {
		write(
"It nearly saddens you to stand up from this extra comfortable chair.\n");
		say(this_player()->query_name()+" stands up, frowning lightly.\n");
		return 1;
	}
	return 0;
}

query_long() {
	extra_reset(100);
	return ::query_long();
}

long(str) {
	extra_reset(100);
	return ::long(str);
}
