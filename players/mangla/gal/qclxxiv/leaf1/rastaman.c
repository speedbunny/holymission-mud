#include "/players/qclxxiv/mymonster.h"
object last, lastgreet, drd;
string lines;
int chant;

set_lines(l) { lines = l; }

reset(arg) {
	object tam;
	last = 0;
	::reset(arg);
	if (arg) return;
	load_chat(5, ({
		"The rastaman smiles iriely.\n",
		"The rastaman is slowly and rythmically shaking his head.\n",
		"The rastaman flashes his dreads through the air.\n",
			})  );
	load_a_chat(15, ({
        "The rastaman looks at you angrily but mostly annoyed.\n",
  		"The rastaman smiles somewhat threatening.\n",
			})  );
	set_lines( ({ "Come Mek We Chant Down Babylon One More Time\n",
				"Come Mek We Chant Down Babylon One More Time\n",
				"For them soft yes them soft\n",
				"Come Mek We Chant Down Babylon One More Time\n",
				}) );
	set_name("rastaman");
	set_level(27);
   	set_wc(27);
   	set_ac(17);
   	set_hp(1777);
	set_sp(100);
   	set_spell_mess1("The rastaman looks his opponent in the eyes.");
   	set_spell_mess2("The rastaman looks you in the eyes.");
	set_chance(25);
	set_spell_dam(30);
    set_al(700);
    load_match(this_object(), ({ 
								 "smoke", ({"smiles", "takes a deep draw",}),
								 "answer", ({"says", "tells you",}),
								"arrives", ({"arrives",}),
								 "receive", ({"gives",}), }));
   	set_aggressive(0);
	set_gender(1);
   	set_short("A rastaman");
   	set_long( "A rastaman, having very long dreadlocks.\n");
	enable_commands();
	set_living_name("rastaman");
	tam = clone_object("/players/qclxxiv/leaf1/tam");	
	if (!tam) { return; }
	move_object(tam, this_object());
	init_command("wear tam");
	drd = clone_object("/players/qclxxiv/leaf1/mdrd");	
	if (!drd) { return; }
	move_object(drd, this_object());
}

init() {
	::init();
	add_action("hold","hold");
	add_action("hold","smash");
	add_action("hold","backstab");
}
		
notify(str) {
	chant = 0;
    say("The rastaman says: "+str);
    write("The rastaman says: "+str);
}
say_room(str) {   /* NOT to be called from actions */
	chant = 0;
    say("The rastaman says: "+str); /* to all in room BUT vendor. */
}

answer(str) {
    string who, lwho, rest, message, a, b, c; 
    sscanf(str, "%s %s", who, rest);
	lwho = lower_case(who);
    if (lwho=="wadden guide") return;
    if (lwho=="guide") return;
    if (id(lwho)) return;
    if (!( sscanf(rest, "says: %s\n", message) 
		|| sscanf(rest, "tells you: %s\n", message) ) ) return;
	message = " " + lower_case(message) + " ."; /* add stuff for easier parse*/
	if (sscanf(message,"%stam%s", a, b)==2) {
		give(who);
		return;
	}
	if (sscanf(message,"%sastafari%s", a, b)) {
		notify("Jah Rastafari!\n");
		return;
	}
	if (sscanf(message,"%ssing%s", a, b)) {
		if (!chant) {
			chant = 1;
			call_out("dochant",1);
		}
		return;
	}
	answer_anyone(who, message);
}

answer_anyone(who, message) {
	do_a_thing();
}
do_a_thing() {
	int i;
	i = random(14);
	switch( i ) {
	case 0 : if (!chant) say("The rastaman scratches behind his ear.\n");
			break;
	case 1 : if (!chant) say("The rastaman frowns.\n");
			break;
	case 2 : smoke( );
			break;
	case 3 : if (!chant) say("The rastaman rubs his beard.\n");
			break;
	case 4: if (!chant) break;
	case 5 : say("The rastaman smiles iriely.\n");
			break;
	case 7: if (!chant) {
				chant = 1;
				call_out("dochant",1);
			}
			break;
	}
}

smoke( arg ) {
	object spliff;
	if (present("spliff",this_object()) && (random(10)>7 || arg) ) 
		init_command("smoke spliff");
	else if (random(10)>7) say("The rastaman smiles iriely.\n");
	else if (random(10)>7) {
		spliff=0;
		PLACE_IN_THIS(spliff,"/players/qclxxiv/spliff");
		say("The rastaman fetches a spliff from somewhere.\n");
	}
}

receive(str) {
	string who, what,coins,me;
	if(sscanf(str,"%s gives you %s.\n",who,what)==2
		|| sscanf(str,"%s gives %s to %s.\n",who,what,me)==3){
		if (me && !id(lower_case(me))) return;
		if (what!="spliff") {
			notify(
				"Thank you for the "+what+", but I really don't need that\n");
			init_command("give "+what+" to "+lower_case(who));
		}
		else {
			notify("Thank you my friend\n");
			smoke("hop");
			init_command("give "+what+" to "+lower_case(who));
		}
	}
}

give(who) {
	object tam, p;
	p = present(lower_case(who), environment(this_object()));
	if (p && living(p) && !(p->query_npc())) {
		if (present("tam",p)) {
			notify("You have a nice tam now eh?\n" );
			return;
		}
		if (p==last) {
			notify("I just gave you a nice tam now didn't I?\n" );
			return;
		}
		notify("Well I do have a tam for you, "+who+"\n");
		tam = clone_object("/players/qclxxiv/leaf1/tam");	
		if (!tam) {
			notify("Hmmm..I lost it. Mus call Qclxxiv for me man.\n");
			return;
		}
		move_object(tam, this_object());
		init_command("give tam to "+who);
		last = p;
	}
}

hold(arg)
{
	if (arg && id(arg)) {
		attack_object(this_player());
		return 1;
	}
}

attack()
{
	if(attacker_ob) {
		attacker_ob->run_away();
	    attacker_ob->stop_fight();
	    attacker_ob->stop_hunter(1);
		lastgreet = attacker_ob->query_real_name();
	}
	stop_fight();
	stop_hunter(1);
	return 0;
	/*return ::attack();*/
}

arrives(str) {
    string who;
    if (sscanf(str, "%s arrives", who) ) {
		if (who!=lastgreet ){
			lastgreet = who;
			say("The rastaman nods friendly.\n");
			write("The rastaman nods friendly.\n");
		}
	}
	if (!chant) {
		chant = 1;
		call_out("dochant",1);
	}
}

dochant() {
	if (!chant || chant>sizeof(lines)) {
		chant = 0;
		return;
	}
	tell_room( environment(this_object()),
			"The rastaman chants: "+lines[chant-1]);
	chant++;
	call_out("dochant",3);
}

second_life() {
	if (drd) destruct(drd);
	return 0;
}

