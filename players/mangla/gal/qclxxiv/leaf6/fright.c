#include "/players/qclxxiv/mymonster.h"
object scratcher;
reset(arg) {
	::reset(arg);
	if (!scratcher) { PLACE_IN_THIS(scratcher,HOME+"leaf6/hscratcher"); }
	if (arg) return;
	load_chat(20,({ 
"Foul fright growls at you.\n",
"Foul fright says: why don't you fuck off?\n",
"Foul fright says: why do you come here to bother me?\n",
"Foul fright says: I really don't need you around here!\n",
"Foul fright looks at you, obviously hating you.\n",
"Foul fright says: all those stupid players are the same.\n",
"Foul fright says: I hate you, I hate you, I hate you!.\n",
	}));
	load_a_chat(20,({ 
"Foul fright growls at you.\n",
"Foul fright spits in your direction.\n",
"Foul fright says: why don't you fuck off NOW?\n",
"Foul fright shouts: I'll crush you you pityful little player.\n",
"Foul fright shouts: I'll crumble yout to dust creep.\n",
	}));
	set_name("fright");
	set_alias("foul fright");
	set_race("skum");
	set_level(30);
   	set_wc(30);
	set_ac(15);
   	set_hp(2100);
	set_sp(100);
   	set_spell_mess1("Foul fright frightens its enemy a bit closer to death.");
   	set_spell_mess2( "Foul fright frightens you a bit closer to death.");
	set_chance(30);
	set_spell_dam(60);
	set_al(-27);
   	set_aggressive(0);
   	set_short("Foul fright");
	set_gender(1);
   	set_long("Foul fright, the frightening fearsome playerhater.\n"+
"He obviously dislikes you, and is waiting for a good moment to get you!\n" );
	set_size(5);
    load_match(this_object(), ({ "receive", ({"gives",}), 
								}));
	enable_commands();
}

receive(str) {
	string who, what,me,dum;
	object letter;
	if(sscanf(str,"%s gives you %s.\n",who,what)==2
		|| (sscanf(str,"%s gives %s to %s.\n",who,what,me)==3 
				&& id(lower_case(me))) ){
		if (what=="letter" && (letter=present("letter172"))) {
			if (sscanf(letter->query_text(),"%s Fright", dum)) {
				say("Foul fright grumbles something.\n");
				write("Foul fright grumbles something.\n");
				say("Foul fright writes a letter.\n");
				write("Foul fright writes a letter.\n");
				say("Foul fright grunts: here, bring this back.\n");
				write("Foul fright grunts: here, bring this back.\n");
				letter->set_read( 
	"Dear Q172,\n (lots of unreadable text)\n regards, Fright\n" );
				letter->set_alias("letter2172");
				init_command("give "+what+" to "+lower_case(who));
				return 0;
			}
		}
		say("Foul fright grumbles something.\n");
		write("Foul fright grumbles something.\n");
	}
}


