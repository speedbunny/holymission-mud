#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
object oldman;
query_qnewbie() { return 1; }

ONE_EXIT( HOME+"leaf3/backhouse2","east",  "Inside a boat shop", 
"Inside a boat shop. A yellowed picture hangs on the wall, as well as numerous\n"
+"yellowed sea-maps. A table is standing in a corner. A few chairs are around\n"
+"it. A few torches spread a flickering orange light.\n", 1)
towadden() { return "west"; }
its_qboatshop() { return 1; }

init() {
	::init();
	add_action( "do_get", "get" );
	add_action("sit", "sit");
	add_action("standup", "stand");
}

extra_reset(arg) {
	PLACE_IN_THIS( oldman, HOME+"leaf3/oldman" );
	if (arg) return;
    set_nodig(1);
	property = ({ "no_fight","no_steal","no_sneak","has_fire" });
	items = ({
		"wall", "A scaled off wooden wall. Not much of its white paint is left",
		"door", "An old oaken door",
		"hinges", "Solid greenish hinges, apparently old copper",
		"lock", "A solid greenish lock, apparently old copper",
		"table", "An old round wooden table",
		"chairs", "Old but solid wooden chairs",
		"chair", "An old but solid wooden chair",
		"picture", "A yellowed picture showing some boats",
		"boats", "The boats on the picture seem to be fishing-boats",
		"maps", "They are old and yellowed",
		"sea-maps", "They are old and yellowed",
		"sea-map", "It is old and yellowed",
		"map", "It is old and yellowed",
				"torches", 
"Modest looking torches, spreading their flickering orange light",
	});
}

light_text(str) {
	write("You light the "+str+" on one of the torches.\n");
	say(this_player()->query_name()+" lights a "+str+",\n"
			+ "on one of the torches.\n");
}

do_get( arg ) {
	if (!arg) return 0;
	switch (arg) {
		case "door" : write("It still hangs firmly in its solid hinges.\n");
						break;
		case "hinges" : write("You can't get them out of the wall.\n"); break;
		case "lock" : write("You fail to rip it out of the door.\n"); break;
		case "wall" : write("How do you plan to carry that?\n"); break;
		case "table" :
		case "chairs" :
		case "chair" :
		case "picture" :
		case "sea-maps" :
		case "torches" :
		case "sea-map" : write("Really...the old man would not like that.\n"
								+"You decide not to take it.\n" ); break;
		case "boats" : write("But they are on the picture only...\n"); break;
		default: return 0;
	}
	return 1;
}

move(arg) {
	if (!arg) arg = query_verb();
	if (arg=="east") {
		if (this_player()->query_name()!="Guide") {
			write("You feel a strange power holding you back...\n");
			write("Apparantly these fishing-folks posses some magic powers.\n");
			write(
"But of course they also could have paid a wizard to install some spell.\n");
			return 1;
		}
		else {
			say("Some light flashes to the east...\n");			
			if (this_player()->is_wadden_guide()) 
				this_player()->dest_soon();
		}
	}
	::move(arg);
	return 1;
}

try_attack(tp) {
	tell_object(tp,"You get kicked out by the old man.\n");
	tp->move_player("kicked","/players/qclxxiv/leaf3/tohouse2");	
	tell_room(this_object(),tp->query_name() 
						+" gets kicked out by the old man.\n");
}

sit(arg) {
	if (arg=="on chair" || arg=="down on chair" )  {
		write("You seat yourself on a chair.\n");
		say(this_player()->query_name()+" seats "+ 
				this_player()->query_objective()
								+"self on a chair.\n", this_player());
	}
	else {
		write("On what?\n");
	}
	return 1;
}

standup(arg) {
	if (arg=="up") {
		say(this_player()->query_name()+" stands up.\n");
		return 1;
	}
	return 0;
}

