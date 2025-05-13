#include "/players/qclxxiv/mymonster.h"
object lastgreet;
object cigar;
string lastlists;
int ll_index;

reset(arg) {
	if (!lastlists) { lastlists = allocate(4); }
	lastlists[0] = lastlists[1] = lastlists[2] = lastlists[3] = 0;
	ll_index = 0;
	::reset(arg);
	if (arg) return;
	set_name("old man");
	set_alias("man");
	set_level(30);
   	set_wc(10);		/*  wc lower than default, hp and ac higher/much higher*/
   	set_ac(100);	/* should not kill fast, not be killed, and keep position*/
   	set_hp(3000);	/* in addition has rather high spell average */
	set_sp(50);		/* besides kicks fighting players out of pub :-) */
   	set_spell_mess1("Old man casts a shock on his attacker.");
   	set_spell_mess2("Old man casts a shock.  Ouffff that hurts.");
	set_chance(20);
	set_spell_dam(30);
    set_al(5);
	set_gender(1);
	load_chat(4, ({
		"Old man coughs noisily.\n",
		"Old man scratches his head.\n",
		"Old man rubs his beard.\n",
		"Old man scratches behind his left ear.\n",
		"Old man scratches behind his right ear.\n",
			})  );
	load_a_chat(15, ({
        "Old man spits in your direction.\n",
  "Old man hisses: you bastard..Don't let my age fool you! I'll eat you raw.\n",
			})  );
    load_match(this_object(), ({ 
								 "smoke", ({"smiles", "takes a deep draw",}),
								 "answer", ({"says", "tells you",}),
								"arrives", ({"arrives",}),
								 "receive", ({"gives",}), }));
   	set_aggressive(0);
   	set_short("Old man");
	set_long(
"An old man. He looks like a fisher-man to you. He has got a big grey beard\n"
+"and may weigh a small 200 pound. Despite his age he looks quite vivid.\n");
	PLACE_IN_THIS(cigar,"/players/qclxxiv/cigar");
	set_living_name( "oldboatman" );
	enable_commands();
}
		
say_room(str) {   /* NOT to be called from actions */
    say("Old man says: "+str); /* to all in room BUT vendor. */
}

answer(str) {
    string who, lwho, rest, message, a, b, c; 
    sscanf(str, "%s %s", who, rest);
	lwho = lower_case(who);
    if (lwho=="wadden guide") return;
    if (lwho=="guide") return;
    if (lwho=="old") return;
    if (!( sscanf(rest, "says: %s\n", message) 
		|| sscanf(rest, "tells you: %s\n", message) ) ) return;
	message = " " + lower_case(message) + " ."; /* add stuff for easier parse*/
	if (sscanf(message,"%sboat%s", a, b)==2) {
		say_room("Well I don't have boats any longer these days.\n");
		say_room("All I can do is get you a good guide.\n");
		return;
	}
	if (sscanf(message,"%smines%s", a, b)==2) {
		say_room( "Hmmmm... the mines eh? Well I don't know actually.\n"
	+"Maybe that beggar knows it, you know, the one in the circular hall\n");
		return;
	}
	if (sscanf(message,"%sguide%s", a, b)==2) {
		maybe_give_list( who, lwho );
		return;
	}
	answer_anyone(who, message);
}

answer_anyone(who, message) {
	if (random(10)>7) say_room( "oh..\n");
	do_a_thing();
}

give_guide(who_obj) {
	string who;
	object guide;
	who = who_obj->query_real_name();
	guide = clone_object("/players/qclxxiv/leaf4/guide");	
	guide->set_myman( who_obj );
	move_object( guide, environment( this_object() ) );
	say( "A gruffly looking man, type sturdy fisherman enters the room.\n");
	log_file("qmap",who_obj->query_real_name()+" guide "+ctime(time())+"\n");
	write_file("/players/qclxxiv/qquest/qmap", who_obj->query_real_name()
			+" guide "+ctime(time())+"\n");
	say_room(
		"My son will follow you now. Ask him to guide you when you want.\n");
	say_room("Now go out of here you two.\n"); 
	say("Old man starts pushing guide and "+who+" to the door.\n");
	guide->init_command("west");
	command("west", who_obj);
	return 1;
}

maybe_give_list( who, lwho ) {
	object who_obj;
	who_obj=present(lwho, environment(this_object()));
	if (!who_obj) { say("Old man looks puzzled.\n"); return 0; }
	if (present("aqlist", who_obj)) {
		say_room( "Hmm... But I think you already have a list, " +who+".\n");
		say_room( "So get me all on the list and don't annoy me now.\n");
	}
	else if ( in_lastlists(lwho) ) {
		say_room( "Hmm... But I think I gave you a list recently, "
					+who+".\n");
		say_room( "Use that one, or come back later.\n");
	}
	else {
		say_room("I could get you a guide. But do me a little favour first.\n");
		say("Old man writes out a list for "+who+".\n");
		call_out("give_list",3,lwho);
	}
}

give_list(who) {
	object alist, who_obj;
	who_obj=present(who, environment(this_object()));
	if (who_obj) {
		alist = clone_object("/players/qclxxiv/leaf3/aqlist");
		if (transfer(alist, who_obj)!=0) {
			move_object(alist, environment(this_object()));
			say("Old man drops a list.\n");
		}
		else tell_object(who_obj,"Old man gives you a list.\n" );
		say_room("Collect the things I have put on the list.\n");
		say_room("You can bring them to me one by one if you like.\n");
		say_room("Just always bring the list with you.\n");
		say_room(
"If you are finished, give me the list and I will get you a guide.\n");
		to_lastlists( who );
		if (!present("qquest_map", who_obj)) {
			tell_object( who_obj,
"Old man tells you: By the way, if you plan to cross the Wadden,\n"
+"  maybe you should get a map first. But with that I can not help you.\n");
		}
	}
	else say("Old man looks puzzled.\n"); 
}

in_lastlists(who) {
	return (lastlists[0]==who || lastlists[1]==who || lastlists[2]==who
		|| lastlists[3]==who);
}

to_lastlists(who) {
	lastlists[ll_index] = who;
	ll_index = (1+ll_index) % 4;
}

receive(str) {
	string who, what;
	object who_obj, what_obj, alist;
	if (sscanf(str,"%s gives you %s.\n",who,what)==2 
			|| sscanf(str,"%s gives %s to Old man",who,what)==2 
			|| sscanf(str,"%s gives %s to Man",who,what)==2) {
		what_obj = present( what, this_object() );
		who_obj = present( lower_case(who) );
		if (!who_obj) {
			say("Old man looks puzzled.\n");
			return 0;
		}
		if (what_obj && what_obj->id("aqlist")) {
			if (what_obj->is_done()) {
				say_room(
					"Thank you "+who+". I will call one of my sons now.\n");
				call_out("give_guide",5,who_obj);
				say("Old man shouts: Son, come here. You have to guide "
					+who+" for me.\n");
				say("Old man destroys a list.\n");
				destruct(what_obj);
				return 0;
			}
			else {
				say_room("Well this list is not yet finished, "+who+".\n");
				say_room("You'd better bring me the remaining stuff.\n");
				say_room("Here you have your list back.\n");
				init_command("give list to "+who);
				return 0;
			}
		}
		else if (what_obj) {
			if (what_obj->customID()) {
				say_room("If I needed items sold in shops, "+who+"...\n");
				say_room("then I would go to a shop.\n");
				say_room("Here you have it back.\n");
				init_command("give "+what+" to "+who);
				return 0;
			}
			else {
				alist = present("aqlist",who_obj);
				if (alist) {
					say_room("Hmm...\n");
					if (alist->check_list(what_obj)) {
						say_room("Well, thank you "+who+".\n");
						tell_object(who_obj,
"Old man seems to have taken your list in some way, and hands it back.\n" );
						say("Old man stows away some "+what+".\n");
						destruct(what_obj);
						return 0;
					}
				}
			}
		}
		say_room("Well, thank you for the "+what+", "+who+".\n");
	}
}

smoke( str ) {
	if (present("cigar",this_object()) && random(10)>6 ) 
		init_command("smoke cigar");
	else if (random(10)>7) say("Old man smiles.\n");
	else if (random(10)>5) {
		cigar = 0;
		PLACE_IN_THIS(cigar,"/players/qclxxiv/cigar");
		say("Old man fetches a cigar from somewhere.\n");
	}
}

do_a_thing() {
	int i;
	i = random(14);
	switch( i ) {
	case 0 : say("Old man scratches behind his ear.\n");
			break;
	case 1 : say("Old man coughs noisily.\n");
			break;
	case 2 : smoke( "hop" );
			break;
	case 3 : say("Old man rubs his beard.\n");
			break;
	case 4 : say("Old man smiles.\n");
			break;
	}
}

arrives(str) {
    string who;
    if (sscanf(str, "%s arrives", who) ) {
		if (who!=lastgreet && who !="Guide") {
			lastgreet = who;
			if (random(10)>5) say_room("Welcome "+who+"\n");
			else if (random(10)>5) say_room("Howdy "+who+"\n");
			else say("Old man nods friendly.\n");
		}
		else if (who=="Guide") 
			say("Old man nods friendly.\n");
	}
}

move_player(arg) {
	::move_player(arg);
	call_out("go_back",0 );
}

go_back() {
	if (environment(this_object())->its_qboatshop()) return;
	say("Old man foots it back to his shop.\n");
	move_object(this_object(), "/players/qclxxiv/leaf3/inhouse2");	
}
