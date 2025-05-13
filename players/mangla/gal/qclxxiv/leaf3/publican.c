#include "/players/qclxxiv/mymonster.h"
object lastgreet;
string lastlists;
int ll_index, ndrops;
int dragontale;

reset(arg) {
	::reset(arg);
	if (arg) return;
	if (!lastlists) { lastlists = allocate(4); }
	lastlists[0] = lastlists[1] = lastlists[2] = lastlists[3] = 0;
	ll_index = 0;
	set_name("publican");
	set_level(30);
   	set_wc(10);
   	set_ac(100);
   	set_hp(1000);
	set_sp(50);
   	set_spell_mess1("Publican jumps up and kicks his opponent's chest.");
   	set_spell_mess2("Publican jumps up and kicks your chest.");
	set_chance(20);
	set_spell_dam(30);
    set_al(5);
	set_gender(1);
	load_chat(4, ({
		"Publican snorts.\n",
		"Publican coughs rattling.\n",
		"Publican burps.\n",
		"Publican pulls his beard.\n",
		"Publican hiccups.\n",
		"Publican tussles his beard.\n",
			})  );
	load_a_chat(15, ({
        "Publican growls at you.\n",
  		"Publican jumps up and down an seems to be quite pliant.\n",
			})  );
    load_match(this_object(), ({ "answer", ({"says", "tells you",}),
								 "drops",  ({"drops",}),
								 "receive", ({"gives",}), }));
   	set_aggressive(0);
   	set_short("Publican");
	set_long(
"The publican of the fisher-men's pub. He looks like an old fisher-man\n"
+"himself, with his weatherbeaten face, big sandy beard and moustache, and\n"
+"a golden ring through his right ear. He is on the heavy side, probably\n"
+"he likes his own beers, but he looks strong as a bear.\n");
	set_living_name( "publican" );
	enable_commands();
}

heart_beat(arg) {
	::heart_beat();
	if (random(30)==10) do_a_thing();
}
		
say_room(str) {   /* NOT to be called from actions */
    tell_room(environment(),"Publican says: "+str); /* to all in room BUT vendor. */
}

answer(str) {
    string who, lwho, message, a, b, c; 
    if (!sscanf(str, "%s says: %s", who, message))
    	if (!sscanf(str, "%s tells you: %s", who, message))
			return;
	lwho = lower_case(who);
    if (lwho=="publican") return;
	message = " " + lower_case(message) + " ."; /* add stuff for easier parse*/
	if (lwho=="drunkard") answer_drunkard(message);
	else if (lwho=="wadden guide") answer_guide(message);
	else answer_anyone(who, message);
}

answer_drunkard(mssg) {
	string a;
	if (sscanf(mssg,"%s has made victims", a))
		call_out("say_room",2,"Stupid adventurers..\n");
	else if (sscanf(mssg,"%s least they could", a))
		call_out("say_room",4,"Well...a map wouldn't hurt as well..hah\n");
}

answer_guide(mssg) {
	string a;
	if (sscanf(mssg,"%s dragon across the wadden",a))
		say_room("Of course, what other dragon?\n");

}

answer_anyone(who, message) {
	string a;
	if (!dragontale && sscanf(message,"%sdragon",a)) {
		do_dragontale();
		return;
	}
	else if (sscanf(message,"%s mines",a))
		call_out( "say_room", 5, "Yeah...Sure the old boat man knows.\n");
	else if (random(10)>7) say_room( "oh..\n");
	else if (random(10)>7) do_a_thing();
}

do_dragontale() {
	say_room("Any news about the dragon?\n"); 
	dragontale = 1;
	call_out("re_dragontale",70);
}

re_dragontale() { dragontale = 0;}

drops(str) {
    string who, rest, what;
	object arrobj, obj;
	int i;
    if (!( sscanf(str, "%s drops %s\n", who, what)==2 ) ) return;
	ndrops++;
	if (ndrops>=7) {
		arrobj = all_inventory(environment(this_object()));
		for (i=0; i<sizeof(arrobj); i++) {
			obj = arrobj[i];
			if (obj->id("qpub_drink") && obj->query_value()<=10) 
				init_command("get "+obj->query_empty_name());
		}
		ndrops = 0;
		call_out("go_cleanup", 2 );
	}
}

go_cleanup() {
	object arrobj;
	int i;
	say("Publican leaves north.\n");
	arrobj = all_inventory(this_object());
	for (i=0; i<sizeof(arrobj); i++) {
		destruct( arrobj[i] );
	}
	say("The sound of tingling glasses is heard from the north.\n");
	say("Publican enters the room again.\n");
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
			|| sscanf(str,"%s gives %s to Publican",who,what)==2) {
		what_obj = present( what, this_object() );
		who_obj = present( lower_case(who) );
		if (!who_obj) {
			say("Publican looks puzzled.\n");
			return 0;
		}
		if (what=="spliff") {
			say_room("Thanks, but I don't smoke that "+who+".\n");
			who = lower_case(who);
			init_command("give spliff to "+who);
		}
		else say_room("Well, thank you for the "+what+", "+who+".\n");
	}
}

do_a_thing() {
	object obj;
	int i;
	i = random(16);
	switch( i ) {
	case 0 : say("Publican tussles his moustache.\n");
			break;
	case 1 : say("Publican coughs rattling.\n");
			break;
	case 3 : say("Publican rubs his beard.\n");
			break;
	case 4 : say("Publican murmurs something unintelligible.\n");
			break;
	case 5: case 6: case 7: case 8: break;
	case 9: if (!dragontale) do_dragontale(); break;
	default:
		if (obj=present("qpub_drink",this_object())) {
			if (obj->query_value()>10) 
				init_command("drink "+obj->query_name());	
			else init_command("drop "+obj->query_empty_name());	
		}
		else {
			if (random(15)==8) {
				PLACE_IN_THIS(obj, HOME+"leaf3/special");
				say("Publican pours himself a glass of herb special.\n");
			}
		}
	}
}

arrives(tp) {
	string who;
	who = tp->query_name();
	if (who=="Guide") {
		say_room("Publican nods friendly towards guide.\n");
		return 0;
	}
	if (in_lastlists(who)) {
		say_room("I don't want you in here anymore "+who+"\n");
		kick_out(tp);
	}
	else if (who!=lastgreet && who!="Guide") {
		lastgreet = who;
      	if (tp->query_quests("island_dragon")) {
			say_room("Welcome great dragon slayer.\n");
		}
		else if (random(10)>5) say_room("Welcome stranger.\n");
		else if (random(10)>5) say_room("Welcome.\n");
		else say_room("Publican nods friendly but looks somewhat suspicious.\n");
	}
}

qpublican() { return 1; }

kick_out( tp ) {
	if (!tp) {
		say("Publican looks puzzled.\n");
		return 1;
	}
	tell_object(tp,
		"Publican seizes you by the collar and carries you to the door.\n");
	say(
"Publican seizes "+tp->query_name()+" by the collar and carries "+
tp->query_objective() +" to the door.\n", tp);
	tell_object(tp,
		"Publican kicks you out.\n");
	tp->move_player("kicked","/players/qclxxiv/leaf3/tohouse3");	
	tell_room(this_object(),tp->query_name() 
						+" gets kicked out by the publican.\n");
	to_lastlists( tp->query_name() );
}

checkout(tp) {
	call_out("arrives",1,tp);
}

drink_alcohol(str) { return 1; }
drink_alco(str) { return 1; }

move_player(arg) {
	::move_player(arg);
	call_out("go_back",0 );
}

go_back() {
	if (environment(this_object())->its_a_qpub()) return;
	say("Publican hurries back to his pub.\n");
	move_object(this_object(), "/players/qclxxiv/leaf3/pub");	
}
