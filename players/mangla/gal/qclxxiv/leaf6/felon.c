#include "/players/qclxxiv/mymonster.h"
object scratcher;
reset(arg) {
	::reset(arg);
	if (!scratcher) { PLACE_IN_THIS(scratcher,HOME+"leaf6/bscratcher"); }
	if (arg) return;
	load_chat(10,({ 
"The fiendish felon eyes you fiendly.\n",
"The fiendish felon grumbles something.\n",
"The fiendish felon burps rudely.\n",
"The fiendish felon pokes you in your ribs.\n",
	}));
	load_a_chat(10,({ 
"The fiendish felon tries to blaze fire at you, but it was touch and go.\n",
"The fiendish felon growls aggressively.\n",
"The fiendish felon tries to get behind you.\n",
"The fiendish felon pokes you in your ribs.\n",
	}));
	set_name("felon");
	set_race("skum");
	set_level(27);
   	set_wc(28);
	set_ac(10);
   	set_hp(1716);
	set_sp(90);
   	set_spell_mess1("The fiendish felon buts his enemy with his head. CRACK.");
   	set_spell_mess2(
"The fiendish felon buts you with his head. It's like a roof comes down on you.");
	set_chance(30);
	set_spell_dam(50);
	set_al(-24);
   	set_aggressive(0);
   	set_short("A fiendish felon");
	set_gender(1);
   	set_long("A fiendish felon. He eyes you fiendly.\n" );
	set_size(4);
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
			if (sscanf(letter->query_text(),"%s Felon", dum)) {
				say("The fiendish felon grumbles something.\n");
				write("The fiendish felon grumbles something.\n");
				say("The fiendish felon writes a letter.\n");
				write("The fiendish felon writes a letter.\n");
				say("The fiendish felon grunts: here, bring this back.\n");
				write("The fiendish felon grunts: here, bring this back.\n");
				letter->set_read( 
	"Dear Q172,\n (lots of unreadable text)\n regards, Felon\n" );
				letter->set_alias("letter2172");
				init_command("give "+what+" to "+lower_case(who));
				return 0;
			}
		}
		say("The fiendish felon grumbles something.\n");
		write("The fiendish felon grumbles something.\n");
	}
}

