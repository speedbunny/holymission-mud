#include "/players/qclxxiv/mymonster.h"
object spliff,lastgreet,last_att;
object myman, mainman;
string mainman_name;
string dirs;
int waited;
reset(arg) {
  object spliff, suitcase, coat;
	::reset(arg);
	if (arg) return;
	waited = 0;
	set_name("monkey");
	set_alias("monkey");
	set_level(50);
   	set_wc(10);
   	set_ac(10000);
   	set_hp(100000);
	/* set_ep(1000); */
	set_sp(100);
   	set_spell_mess1(
			"The monkey jumps up and kicks his attacker badly.");
   	set_spell_mess2("The monkey jumps up and kicks you badly.");
	set_chance(10);
	set_spell_dam(100);
    set_al(15);
	load_chat(5, ({
		"monkey says: Me have good spliffs you know!\n",
		"monkey says: 300 coins a spliff man!\n",
		"monkey whispers: psst! You wan fe buy spliffs man?\n",
		"monkey hisses: Ishens for sale!  Buy me ishens!\n",
		"monkey says: Just give me 300 coins man.\n",
		"monkey whispers: Sensimilla spliff for 300!\n",
"monkey sings: I got a stock of sensimilla, glooming in my pocket.\n",
"monkey says: The demands are big and the harvest has been poor.\n"+
"My costs are high so i had to raise my prices. I have to feed my family man.\n",
			})  );
	load_a_chat(25, ({
        "monkey shouts: You fool! I'll crush you!\n",
        "monkey shouts: I'll break your neck!\n",
        "monkey spits in your direction.\n",
        "monkey looks very very angry.\n",
			})  );
    load_match(this_object(), ({ "follow",  ({"leaves",}),
								 "smoke", ({"smiles", "takes a deep draw",}),
								"follow2", ({"disappears",}),
								"dofollow", ({"do follow",}),
								"dotake", ({"do take",}),
								 "answer", ({"says", "tells you",}),
								 "receive", ({"gives",}), }));

   	set_aggressive(0);
   	set_short("monkey");
   	set_long(
"monkey (good).\n"+
"monkey has a scar on his left arm, his right arm and his left cheek.\n"+
"He is in good shape.\n"+
"He has an account at the Money Brokers Assoc.\n"+
"monkey is a male Human.\n"+
"Friendly as he may seem, the man doesn't look like someone to play with.\n"
		 );
	enable_commands();
	init_dirs();
	set_living_name("monkey");
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
    say("monkey says: "+str); /* to all in room BUT monkey. */
}

follow(str) {
    string who, where;
    if (sscanf(str, "%s leaves %s.\n", who, where) == 2)
	{
		if (capitalize(who)==mainman_name) {
			if (where=="home") {
			/* if (myman) move_object( myman, environment(mainman) ); */
			move_object(this_object(), environment(mainman) );
	 		if (myman)
				myman->move_player("following#"+file_name(environment(mainman)) ); 
			}
			else {
				/*if (myman) call_other( myman, "init_command", where );*/
				if (myman) command( where, myman);
				/*init_command(where);*/
				command(where);
			}
		}
	}
}

follow2(str) {
    string who, where;
    if (sscanf(str, "%s disappears in a puff of smoke.\n", who) == 1)
	{
		if (capitalize(who)==mainman_name) {
			/* if (myman) move_object( myman, environment(mainman) ); */
			move_object(this_object(), environment(mainman) );
			say("Monkey arrives.\n");
	 		if (myman)
				myman->move_player("following#"+file_name(environment(mainman)) ); 
		}
	}
}

dofollow(str) {
    string who, someone;
    if (sscanf(str, "%s do follow %s\n", someone, who) == 2) {
		if (who=="me") {
			sscanf(str, "%s says", who);
			who = lower_case(who);
		}
		mainman = present(who);
		if (!mainman) say("cant find_living, must be present\n");
		say("Yes I! I'll follow "+who+".\n");
		mainman_name = capitalize(who);
	}
}

dotake(str) {
    string who, someone;
    if (sscanf(str, "%s do take %s\n", someone, who) == 2) {
		myman = present(who);
		if (!myman) say("cant find_living, must be present\n");
		say("Yes I! I'll take with me "+who+".\n");
	}
}

arrives(str) {
    string who;
	waited = 0;
    if (sscanf(str, "%s arrives", who) ) {
		if (who!=lastgreet) {
			lastgreet = who;
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
	if (sscanf(str,"%s gives you %s",who,what)==2 
			|| sscanf(str,"%s gives %s to monkey",who,what)==2) {
		if (sscanf(what, "%d gold coins", coins)==1) {
			if (coins>=300) {
				say("The monkey smiles his big smile.\n" );
				num = coins / 300;
				for (t=1; t<=num; t++) {
					spliff=clone_object("/players/qclxxiv/obj/spliff_s");
					move_object(spliff,find_player( lower_case(who) ) );
				}
/*				write("The monkey gives you "+num+" spliffs.\n"); */
				if (num>1)
					say("The monkey gives "+who+" "+num+" spliffs.\n");
				else
					say("The monkey gives "+who+" one good spliff.\n");
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
	"monkey tells you: "+
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
	else if (random(10)>6) say("monkey smiles encouraging.\n");
	else if (random(10)>6) {
		PLACE_IN_THIS(spliff,"/players/qclxxiv/obj/spliff_s");
		say("monkey takes a spliff out of his suitcase.\n");
	}
}

hit_player(dam) {
	set_heart_beat(1);
	if (random(10)>6) write("monkey laughs at you.\n");
	else if (random(10)>6) write("monkey seems to be untouchable.\n");
	return ::hit_player(dam/10);
}

reduce_hit_point(dam) {
	set_heart_beat(1);
	if (random(10)>6) write("monkey laughs at you.\n");
	else if (random(10)>6) write("monkey seems to be untouchable.\n");
	return ::reduce_hit_point(dam/10);
}

answer(str) {
    string who, rest, message, a, b, c; 
	waited = 0;
    sscanf(str, "%s %s", who, rest);
    if (lower_case(who)=="monkey") return;
    if (lower_case(who)=="monkey") return;
    if (!( sscanf(rest, "says: %s\n", message) 
		|| sscanf(rest, "tells you: %s\n", message) ) ) return;
	message = lower_case(message) + " .";
	if ( sscanf(message, "%sspliff%s", a,b) ) {
		if (random(10)>4) notify("What about spliffs?\n");
	}
	else if ( sscanf(message, "%smonkey%s", a,b) ) {
		if ( sscanf(a,"hi%s",c) || sscanf(a,"hello%s",c) ) {
			if (random(10)>3) say("monkey smiles his big smile.\n");
			else if (random(10)>3) say("monkey nods friendly.\n");
		}
		else if (random(10)>3) notify("What about me?\n");
	}
	else if ( sscanf(message, "%sqclxxiv%s", a,b) ) {
		if (random(10)>3) notify("What about Negus Qclxxiv?\n");
	}
	else if ( sscanf(message, "%sprice%s", a,b)
			|| sscanf(message, "%scost%s", a,b)
			|| sscanf(message, "%scoins%s", a,b)  ) {
		if (random(10)>2) notify("The spliffs are 300 coins a piece.\n");
	}
	else { do_a_thing(); }
}

do_a_thing() {
	int i;
	i = random(18);
	if (i<4) { if (i<2) { if (i==1) say("monkey scratches his head.\n");
			else      say("monkey seems to think deeply.\n"); }
		else { if (i==3) say("monkey scratches his head.\n");
			else      smoke(); }
	} else { if (i<6) { if (i==5) say("monkey smiles.\n");
			else      say("monkey coughs.\n"); }
		else { if (i==7) say("monkey spits on the floor.\n");
			else  if (i==8) say("monkey shrugs helplessly.\n"); 
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

