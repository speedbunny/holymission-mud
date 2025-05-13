#include "/players/qclxxiv/mymonster.h"
object spliff,lastgreet,last_att;
string dirs;
int waited;
reset(arg) {
  object spliff, suitcase, coat;
	::reset(arg);
	if (arg) return;
	waited = 0;
	set_name("vendor");
	set_alias("ishen vendor");
	set_level(50);
	/* wc lower than default (and ac and hp MUCH higher) because: */
	/* should not kill easy   but also not be easily killed */
	/* and should stay at his position */
   	set_wc(10);
   	set_ac(10000);
   	set_hp(100000);
	/* set_ep(1000); */
	set_sp(100);
   	set_spell_mess1(
			"The ishen vendor jumps up and kicks his attacker badly.");
   	set_spell_mess2("The ishen vendor jumps up and kicks you badly.");
	set_chance(10);
	set_spell_dam(100);
    set_al(15);
	load_chat(18, ({
		"Ishen vendor says: Me have good spliffs you know!\n",
		"Ishen vendor says: 300 coins a spliff man!\n",
		"Ishen vendor whispers: psst! You wan fe buy spliffs man?\n",
		"Ishen vendor hisses: Ishens for sale!  Buy me ishens!\n",
		"Ishen vendor says: Just give me 300 coins man.\n",
		"Ishen vendor whispers: Sensimilla spliff for 300!\n",
"Ishen vendor sings: I got a stock of sensimilla, glooming in my pocket.\n",
"Ishen vendor says: The demands are big and the harvest has been poor.\n"+
"My costs are high so i had to raise my prices. I have to feed my family man.\n"
			})  );
	load_a_chat(25, ({
        "Ishen vendor shouts: You fool! I'll crush you!\n",
        "Ishen vendor shouts: I'll break your neck!\n",
        "Ishen vendor spits in your direction.\n",
        "Ishen vendor looks very very angry.\n",
			})  );
    load_match(this_object(), ({ "follow",  ({"leaves",}),
								 "smoke", ({"smiles", "takes a deep draw",}),
								 "answer", ({"says", "tells you",}),
								"whatru", ({"looks at you",}),
								"arrives", ({"arrives",}),
								 "receive", ({"gives",}), }));
   	set_aggressive(0);
   	set_short("Ishen vendor");
   	set_long(
"Ishen vendor (good).\n"+
"Ishen vendor has a scar on his left arm, his right arm and his left cheek.\n"+
"He is in good shape.\n"+
"He has an account at the Money Brokers Assoc.\n"+
"Ishen vendor is a male Human.\n"+
"Friendly as he may seem, the man doesn't look like someone to play with.\n"
		 );
	enable_commands();
	init_dirs();
	set_living_name("ishenvendor");
	PLACE_IN_THIS(suitcase,"/players/qclxxiv/obj/suitcase");
	spliff=clone_object("/players/qclxxiv/obj/spliff_s");
	move_object(spliff,suitcase);
	coat=clone_object("/players/qclxxiv/obj/qcloak");
	coat->name_qcloak("coat");
	coat->suf_qcloak("with many pockets (worn)");
	move_object(coat,this_object());
/*
	init_command("wear coat"); 
*/
}
		
notify(str) {   /* NOT to be called from actions */
    say("Ishen vendor says: "+str); /* to all in room BUT vendor. */
}

follow(str) {
    string who, where;
	waited = 0;
	if (random(10)>3) return;
    if (sscanf(str, "%s leaves %s.\n", who, where) == 2)
			command(where);
			/* init_command(where); */
}

arrives(str) {
    string who;
	object owho;
	waited = 0;
    if (sscanf(str, "%s arrives", who) ) {
		if (who!=lastgreet) {
			lastgreet = who;
			owho = present(lower_case(who),environment());
			if (owho && present("qganjasoul",owho)) {
				if (random(10)>5) {
					notify("Pssst.... I have very good spliffs you know.\n");
					return;
				}
			}
			if (random(10)>5) notify("Hi "+who+"\n");
			else if (random(10)>5) notify("Hi\n");
			else notify("Hello "+who+", what's up\n");
		}
	}
}

receive(str) {
	string who, what;
	int coins, num, t;
	object spliff;
	waited = 0;
	if (sscanf(str,"%s gives you %s.",who,what)==2 
			|| sscanf(str,"%s gives %s to Vendor",who,what)==2) {
		if (sscanf(what, "%d gold coins", coins)==1) {
			if (coins>=300) {
				say("The ishen vendor smiles his big smile.\n" );
				num = coins / 300;
				for (t=1; t<=num; t++) {
					spliff=clone_object("/players/qclxxiv/obj/spliff_s");
					move_object(spliff,find_player( lower_case(who) ) );
				}
/*				write("The ishen vendor gives you "+num+" spliffs.\n"); */
				if (num>1)
					say("The ishen vendor gives "+who+" "+num+" spliffs.\n");
				else
					say("The ishen vendor gives "+who+" one good spliff.\n");
				if (num*300 < coins) 
					notify("thanks for the tip btw.\n");
			}
			else notify("Well spliffs cost 300. So I take that as a gift.\n");
		}
		else notify("Thank you for the "+what+", "+who+"!\n");
	}
}

attack() {
	if (attacker_ob) {
		/* last_att = attacker_ob; */
		if (attacker_ob->query_level()<10) {
			tell_object( attacker_ob,
	"Ishen vendor tells you: "+
	"Would you have had a higher level, I'd have crushed you!\n"
	+"But this time I'll spare you. Now get the fuck out of here!\n"	
					 );
			stop_fight();
			stop_hunter(1);
			attacker_ob->stop_fight();
			attacker_ob->stop_hunter(1);
		}
		return;
	}
	/* else last_att = 0; */
	stop_fight();
	stop_hunter(1);
}

smoke() {
	waited = 0;
	if (present("spliff",this_object())) {
		init_command("smoke spliff");
	}
	else if (random(10)>6) say("Ishen vendor smiles encouraging.\n");
	else if (random(10)>6) {
		PLACE_IN_THIS(spliff,"/players/qclxxiv/obj/spliff_s");
		say("Ishen vendor takes a spliff out of his suitcase.\n");
	}
}

hit_player(dam) {
	set_heart_beat(1);
	if (random(10)>6) write("Ishen vendor laughs at you.\n");
	else if (random(10)>6) write("Ishen vendor seems to be untouchable.\n");
	return ::hit_player(dam/10);
}

reduce_hit_point(dam) {
	set_heart_beat(1);
	if (random(10)>6) write("Ishen vendor laughs at you.\n");
	else if (random(10)>6) write("Ishen vendor seems to be untouchable.\n");
	return ::reduce_hit_point(dam/10);
}

answer(str) {
    string who, rest, message, a, b, c; 
	waited = 0;
    sscanf(str, "%s %s", who, rest);
    if (lower_case(who)=="ishen vendor") return;
    if (lower_case(who)=="vendor") return;
    if (!( sscanf(rest, "says: %s\n", message) 
		|| sscanf(rest, "tells you: %s\n", message) ) ) return;
	message = lower_case(message) + " .";
	if ( sscanf(message, "%sspliff%s", a,b) ) {
		if (random(10)>4) notify("What about spliffs?\n");
		else 
		notify("Just gimme 300 coins, and you'll get one VERY good spliff.\n");
	}
	else if ( sscanf(message, "%svendor%s", a,b) ) {
		if ( sscanf(a,"hi%s",c) || sscanf(a,"hello%s",c) ) {
			if (random(10)>3) say("Ishen vendor smiles his big smile.\n");
			else if (random(10)>3) say("Ishen vendor nods friendly.\n");
		}
		else if (random(10)>3) notify("What about me?\n");
	}
	else if ( sscanf(message, "%sqclxxiv%s", a,b) ) {
		if (random(10)>3) notify("What about Negus Qclxxiv?\n");
	}
	else if ( sscanf(message, "%sprice%s", a,b)
			|| sscanf(message, "%scost%s", a,b)
			|| sscanf(message, "%scost", a)
			|| sscanf(message, "%sprice", a)
			|| sscanf(message, "%sspliff", a)
			|| sscanf(message, "how much%s", a)
			|| sscanf(message, "%sbuy%s", a,b)
			|| sscanf(message, "%scoins%s", a,b)  ) {
		if (random(10)>2) notify("The spliffs are 300 coins a piece.\n");
	}
	else { do_a_thing(); }
}

do_a_thing() {
	int i;
	i = random(18);
	if (i<4) { if (i<2) { if (i==1) say("Ishen vendor scratches his head.\n");
			else      say("Ishen vendor seems to think deeply.\n"); }
		else { if (i==3) say("Ishen vendor scratches his head.\n");
			else      smoke(); }
	} else { if (i<6) { if (i==5) say("Ishen vendor smiles.\n");
			else      say("Ishen vendor coughs.\n"); }
		else { if (i==7) say("Ishen vendor spits on the floor.\n");
			else  if (i==8) say("Ishen vendor shrugs helplessly.\n"); 
				else  if (i==9) notify("Nice weather, isn't it?\n"); }
	}
}

heart_beat() {
	if (++waited>16) { waited = 10; do_a_move(); }
    if (attacker_ob && !present(attacker_ob, environment(this_object())) ) 
		{ a_chat_chance = 0; chat_chance = 18; }
	else { a_chat_chance = 25; chat_chance = 0; }
	::heart_beat();
}

do_a_move() {
	if (random(10)==1) {
		if (file_name(environment(this_object()))=="room/church" ) {
			init_command("south");
		}
		else {
			notify("Well I think I go to the church. It's too quiet here.\n");
			say("Ishen vendor disappears in a puff of smoke.\n");
			move_object( this_object(), "/room/church" );
			say("Ishen vendor appears in a puff of smoke.\n");
		}
	}
	command( dirs[random(17)] );
	/* init_command( dirs[random(17)] );*/
}

init_dirs() {
	dirs = allocate(17);
	dirs = ({ "east","west","south","north","up","down","northeast",
			  "northwest","southeast","southwest","eastup","westup",
			  "eastdown","westdown","back","enter castle" ,"open door"
			});
}

whatru() {
	notify("What are you looking at?");
}

