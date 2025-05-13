#include "/players/qclxxiv/mymonster.h"
object lastgreet;
string lastlists;
int ll_index;

reset(arg) {
	::reset(arg);
	if (arg) return;
	if (!lastlists) { lastlists = allocate(4); }
	lastlists[0] = lastlists[1] = lastlists[2] = lastlists[3] = 0;
	ll_index = 0;
	set_name("drunkard");
	set_level(30);
   	set_wc(10);		/*  wc lower than default, hp and ac higher/much higher*/
   	set_ac(100);	/* should not kill fast, not be killed, and keep position*/
   	set_hp(3000);	/* in addition has rather high spell average */
	set_sp(50);		/* besides publican kicks out fighting players */
   	set_spell_mess1("Drunkard kicks his attacker in the stomach.");
   	set_spell_mess2("Drunkard kicks you in the stomach.");
	set_chance(20);
	set_spell_dam(30);
    set_al(0);
	set_gender(1);
	load_chat(4, ({
		"Drunkard coughs noisily.\n",
		"Drunkard hiccups.\n",
		"Drunkard coughs rattling.\n",
		"Drunkard burps.\n",
		"Drunkard rubs his beard.\n",
		"Drunkard hiccups.\n",
		"Drunkard tussles his moustache.\n",
		"Drunkard burps.\n",
			})  );
	load_a_chat(15, ({
        "Drunkard growls at you.\n",
  		"Drunkard jumps up and down an seems to be quite pliant.\n",
			})  );
    load_match(this_object(), ({ "answer", ({"says", "tells you",}),
								"arrives", ({"arrives",}),
								 "receive", ({"gives",}), }));
   	set_aggressive(0);
   	set_short("Drunkard");
	set_long(
"A drunkard. He looks like an old fisher-man. His grey beard and moustache\n"
+"are still wet from the last booze he had. \n" );
	set_living_name( "drunkard" );
	enable_commands();
}

heart_beat(arg) {
	::heart_beat();
	if (random(20)==10) do_a_thing();
}
		
say_room(str) {   /* NOT to be called from actions */
    say("Drunkard says: "+str); /* to all in room BUT vendor. */
}

answer(str) {
    string who, lwho, message, a, b, c; 
    if (!sscanf(str, "%s says: %s", who, message))
    	if (!sscanf(str, "%s tells you: %s", who, message))
			return;
	lwho = lower_case(who);
    if (lwho=="drunkard") return;
	message = " " + lower_case(message) + " ."; /* add stuff for easier parse*/
	if (lwho=="publican") answer_publican(message);
	else if (lwho=="wadden guide") answer_guide(message);
	else answer_anyone(who, message);
}

answer_publican(mssg) {
	string a;
	if (sscanf(mssg,"%s news about the dragon",a))
		call_out( "say_room", 3, "Well he has made victims again recently.\n");
	else if (sscanf(mssg,"%supid adventurers",a))
		call_out( "say_room", 4, 
			"The least they could do is go there by help of a guide.\n");
}

answer_guide(mssg) {

}

answer_anyone(who, message) {
	string a;
	if (sscanf(message,"%s mines",a))
		call_out( "say_room", 3, "I guess the boat man knows.\n");
	else if (random(10)>7) say_room( "oh..\n");
	if (random(10)>7) do_a_thing();
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
			|| sscanf(str,"%s gives %s to Drunkard",who,what)==2) {
		if (who=="Publican") {
			say_room("thanks\n");
			return 0;
		}
		what_obj = present( what, this_object() );
		who_obj = present( lower_case(who) );
		if (!who_obj) {
			say("Drunkard looks puzzled.\n");
			return 0;
		}
		say_room("Well, thank you for the "+what+", "+who+".\n");
	}
}

do_a_thing() {
	object obj;
	int i;
	i = random(14);
	switch( i ) {
	case 0 : say("Drunkard scratches behind his ear.\n");
			break;
	case 1 : say("Drunkard scratches his head.\n");
			break;
	case 3 : say("Drunkard rubs his moustache.\n");
			break;
	case 4 : say("Drunkard murmurs something unintelligible.\n");
			break;
	case 5 : if (present("spliff",this_object()))
				init_command("smoke spliff");
			break;
	case 6: case 7: case 8: break;
	default :
		if (obj=present("qpub_drink",this_object())) {
			if (obj->query_value()>10) 
				init_command("drink "+obj->query_name());	
			else init_command("drop "+obj->query_empty_name());	
		}
		else {
			if (random(10)>7) {
				add_money(100);
				if (query_money()>250) init_command("buy special");
			}
			else {
				add_money(50);
				if (query_money()>155) init_command("buy triple");
			}
		}
	}
}


arrives(str) {
    string who;
    if (sscanf(str, "%s arrives", who) ) {
		if (who!=lastgreet && who !="Guide") {
			lastgreet = who;
			if (random(10)>5) say_room("Hi\n");
			else if (random(10)>5) say_room("Hello\n");
			else say("Drunkard nods friendly.\n");
		}
		else if (who=="Guide") 
			say("Drunkard nods friendly.\n");
	}
}

drink_alcohol(str) { return 1; }
drink_alco(str) { return 1; }

move_player(arg) {
	::move_player(arg);
	call_out("go_back",0 );
}

go_back() {
	if (environment(this_object())->its_a_qpub()) return;
	say("Drunkard rushed back to the pub.\n");
	move_object(this_object(), "/players/qclxxiv/leaf3/pub");	
}
