#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
object publican, drunkard;
int notfirst;
string *doubles_sent_by; // moonchild 130893

query_qnewbie() { return 1; }

ONE_EXIT( HOME+"leaf3/backhouse3","north",  "Inside a fisher-men's pub", 
"Inside a fisher-men's pub. A table and some chairs to the east, a bar\n"
+"with some bar stools to the west. Bottles of various kinds are displayed on\n"
+"shelves on the wall behind the bar, as well as glasses and jugs of several\n"
+"sizes. Torches are lightening the room. A list on the same wall shows the\n"
+"pub's prices. A board is mounted to the opposite wall, close to the door.\n"
+"A shiny copper bell is mounted on the bar. The door is to the south.\n"
,1)
towadden() { return "south"; }
its_a_qpub() { return 1; }

init() {
	::init();
	add_action( "do_get", "get" );
    add_action("read_list", "read");
	add_action("sit", "sit");
	add_action("standup", "stand");
	add_action("move", "enter");
	add_action("move", "north");
	add_action("move", "south");
	add_action("buy", "buy" );
	add_action("buy", "order" );
	add_action("ring", "ring" );
	if (notfirst) {
		if (this_player()!=publican) get_publican_here();
		if (publican && this_player()!=publican) {
			publican->checkout(this_player());
		}
	}
}

extra_reset(arg) {
	if (!publican) PLACE_IN_THIS( publican, HOME+"leaf3/publican" );
	if (!drunkard) PLACE_IN_THIS( drunkard, HOME+"leaf3/drunkard" );
	doubles_sent_by=({});
	if (arg) return;
	notfirst = 1;
    set_nodig(1);
	property = ({ "no_fight","no_steal","no_sneak","has_fire" });
	items = ({
		"wall", "A scaled off wooden wall. Not much of its white paint is left",
		"floor","A stained wooden floor",
		"door", "An old wooden door",
		"hinges", "Solid hinges, apparently bronze",
		"lock", "A solid lock, apparently bronze",
		"table", "An old round table with a stained surface",
		"chairs", "Old wooden chairs",
		"chair", "An old wooden chair",
		"stools","Old but solid bar-stools, mounted to the floor",
		"stool","An old but solid bar-stool, mounted to the floor",
		"bar", "A stained wooden bar, rings allover its surface",
		"bottles","Various liquors displayed behind the bar",
		"shelves","Shelves carrying bottles of liquor and glasses",
		"shelf","A shelf carrying bottles of liquor",
		"glasses","All kinds of glasses and jugs",
		"jugs","All kinds of jugs",
		"list","A list showing the pub's prices",
		"board","A wooden board with some warnings written on it",
				"torches", 
"Massive torches, spreading their flickering yellow-orange light",
		"bell",
		"A bell with a small sign on it. It seems one can ring the bell",
		"sign", "A small sign mounted on the bell",
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
		case "bar" :
		case "wall" : write("How do you plan to carry that?\n"); break;
		case "bottles" :
		case "glasses" :
		case "jugs" : write(
				"You cannot take the ones behind the bar of course.\n"); break;
		case "table" :
		case "chairs" :
		case "stools" : 
		case "stool" :
		case "list" :
		case "board" :
		case "torches" :
		case "chair": write("The publican doesn't look happy with your plans.\n"
								+"You decide not to take it.\n" ); break;
		case "shelf" :
		case "shelves": write(
					"The publican wouldn't let you go behind the bar.\n");
						break;
		default: return 0;
	}
	return 1;
}

clone_drink(arg) {
	object drink;
	switch(arg) {
		case "herb" : case "special" : case "herb special" :
			drink = clone_object(HOME+"leaf3/special"); break;
		case "corn" : case "wine" : 	case "corn wine" :
			drink = clone_object(HOME+"leaf3/cornwine"); break;
		case "triple" : case "island" : case "island triple" :	
			drink = clone_object(HOME+"leaf3/triple"); break;
		case "double" :	case "island double" :
			drink = clone_object(HOME+"leaf3/double"); break;
		case "dyke" : case "tea" : case "dyke tea" :
			drink = clone_object(HOME+"leaf3/dyketea"); break;
		case "flu" : case "flu herbs" : case "herbs" :
			drink = clone_object(HOME+"obj/fluherbs"); break;
	}
	return drink; /* 0 if we don't have it. */
}

read_list(str) {
    if (str=="list") { 
		write(" Herb special - 250\n");
		write("    Corn wine - 150\n");
		write("Island triple - 100\n");
		write("Island double -  50\n");
		write("     Dyke tea -  25\n");
		write("    Flu herbs - 700\n");
		write("(just: buy something or order something to get it)\n");
    	return 1;
	}
    if (str=="board" || str=="warnings") { 
		write("Fighting is not allowed in here!\n");
		write("Glasses, bottles, etc. should be left in the pub!\n");
		write("We don't sell on tick!\n");
		write("Spending time but not a dime can be done outside!\n");
		write("   signed: your Publican\n");
    	return 1;
	}
	else if (str=="sign") {
		write("Ring this bell if you want to stand drinks all around.\n");
		write("The special gift-quality double beer is 16 coins a bottle.\n");
		write("The round will be mud-wide. You may only stand drinks once\n");
		write("per game reset.\n"); // moonchild 130893
		return 1;
	}
	return 0;  
}

ring(str) {
	object u,b; 
	int i, cost;
	if (str!="bell") return 0;
	if(member_array(this_player()->query_real_name(), doubles_sent_by)!=-1)
		{
		write("You have already stood drinks recently.\n");
		return 1;
	}
	doubles_sent_by+=({ this_player()->query_real_name() });
	u=users();
	cost = 2*sizeof(u) * "/players/qclxxiv/obj/rounddouble"->query_value();
    if (call_other(this_player(), "query_money", 0) < cost) {
		write(
"A round would cost you "+cost+" gold coins, which you don't seem to have.\n");
		return 1;
    }
	write("This round is gonna cost you "+cost+" gold coins.\n");
	cost = 2*"/players/qclxxiv/obj/rounddouble"->query_value();
	for (i=0; i<sizeof(u); i++) {
		tell_object(u[i], str+"\n");
		b = clone_object("/players/qclxxiv/obj/rounddouble");
		if (!b) break;
		b->set_giver(this_player());
		if (transfer(b, u[i])==0) {
			write("You give a double to "+u[i]->query_name()+".\n");
			tell_object(u[i],this_player()->query_name()
						+" stands drinks and sends you a double beer.\n");
    		call_other(this_player(), "add_money", -cost);
		}
		else {
			write("You fail to give a double to "+u[i]->query_name()
						+", perhaps it is too heavy now. Nothing charged.\n");
			destruct(b);
		}
	}
	return 1;
}

buy(arg) {
	object obj;
	int val;
	get_publican_here();
	arg = lower_case(arg);
	if ( obj = clone_drink(arg)) {
		say(this_player()->query_name()+" orders one "+arg+".\n",this_player());
		val = obj->query_value();
		if (this_player()->query_money()<val) {
			tell_object(this_player(),
"Publican tells you: I don't think you have "+val+" goldies anymore.\n");
			destruct(obj);
		}
		else if (transfer(obj, this_player())!=0) {
			tell_object(this_player(),
"Publican tells you: you can't carry that now, drop some stuff.\n");
			destruct(obj);
		}
		else {
			this_player()->add_money( -val );
			tell_object(this_player(), "Publican gives you your "+arg
									+". You pay "+val+" gold coins.\n");
			say("Publican gives "+this_player()->query_name()
						+" "+this_player()->query_possessive()
						+" "+arg+"\n", this_player());
		}
	}
	else tell_room(this_object(), "Publican says: we don't sell "
				+arg+", "+this_player()->query_name()+"\n");
	return 1;
}

sit(arg) {
	if (arg=="on stool" || arg=="down on stool" ) {
		write("You seat yourself on a stool.\n");
		say(this_player()->query_name()+" seats "
					+ this_player()->query_objective()
								+"self on a stool.\n", this_player());
	}
	else if (arg=="on chair" || arg=="down on chair" )  {
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

/*
exit(tp) {
	::exit();
	if (has_qpub_drink(tp)) {
		tell_object( tp, 
"Publican tells you: very well..if you think you can steal from me...\n");
		tell_object( tp, 
"Publican tells you: But you need not come back here anymore.\n");
		get_publican_here();
		publican->to_lastlists(tp->query_name());
	}
}
*/

move(arg) {
	object obj;
	if (!arg) arg = query_verb();
	if (arg=="north") {
		if (this_player()->query_name()!="Publican") {
			write("You feel a strange power holding you back...\n");
			write("It seems the publican has done some business with a wiz.\n");
			return 1;
		}
		else { say("Some light flashes to the north...\n");			}
	}
/*
	else if (arg=="south" || arg=="door") {
		if (has_qpub_drink(this_player())) {
			if (this_player()->is_wadden_guide()) {
				while (obj=present("qpub_drink",this_player())) {
					move_object(obj, this_object());
					say("Guide puts down "+obj->short()+".\n",this_player());
				}
			}
			else {
				get_publican_here();
				tell_room(this_object(), 
						"Publican says: glasses, bottles etc. should stay here "
						+this_player()->query_name()+"\n");
			}
		}
		else this_player()->move_player("south",HOME+"leaf3/tohouse3");
		return 1;
	}
*/
	::move(arg);
	return 1;
}

try_attack(tp) {
	kick_out( tp );
}

kick_out( tp ) {
	get_publican_here();
	publican->kick_out( tp );	
}

get_publican_here() {
	if (!publican) {
		publican = clone_object("/players/qclxxiv/leaf3/publican");
		move_object(publican, this_object() );
	}
	else if (environment(publican)!=this_object()) 
			move_object(publican, this_object() );
}

has_qpub_drink(tp) {
	object obj;
	obj = first_inventory(tp);
	while(obj) {
		if (obj->id("qpub_drink")) return 1;
		if (obj->can_put_and_get()) 
			if (has_qpub_drink(obj)) return 1;
		obj = tp->next_inventory(obj);
	}
	return 0;
}
