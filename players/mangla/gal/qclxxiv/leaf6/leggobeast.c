#include "/players/qclxxiv/mymonster.h"
object purse;
reset(arg) {
	::reset(arg);
	if (!purse) { PLACE_IN_THIS(purse,HOME+"leaf6/purse"); }
	purse->add_stored(1256+random(1000));
	if (arg) return;
	load_chat(20,({ 
"Leggo beast smiles charmingly at you.\n",
"Leggo beast says: why don't you stay here a while?\n",
"Leggo beast says: We could become friends.\n",
"Leggo beast looks at you, seemingly liking you.\n",
"Leggo beast says: don't take life too seriously.\n",
"Leggo beast says: take care of yourself in the first place.\n",
"Leggo beast says: Have fun, have fun. What would you care about?\n",
"Leggo beast says: Have fun whenever you can, whereever you can!\n",
	}));
	load_a_chat(20,({ 
"Leggo beast says: stop this and become my friend. Why fight?\n",
"Leggo beast tries to kick you lowly.\n",
"Leggo beast tries to bite you.\n",
"Leggo beast shout: You FOOL. Think of all the things I could have done for you.\n",
"Leggo beast says: I hate you.\n",
	}));
	set_name("beast");
	set_alias("leggo beast");
	set_race("skum");
	set_level(28);
   	set_wc(29);
	set_ac(13);
   	set_hp(1900);
	set_sp(90);
   	set_spell_mess1("Leggo beast casts a spell on its attacker.");
   	set_spell_mess2( "Leggo beast casts a spell on you. You feel weakened.");
	set_chance(40);
	set_spell_dam(40);
	set_al(-25);
   	set_aggressive(0);
   	set_short("Leggo beast");
	set_gender(0);
   	set_long("Charming leggo beast. Leggo beast looks deceivingly friendly.\n"+
"It takes a form precisely so as to deceive you, but beware!\n" );
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
			if (sscanf(letter->query_text(),"%s Leggo", dum)) {
				say("Leggo beast whispers something.\n");
				write("Leggo beast whispers something.\n");
				say("Leggo beast writes a letter.\n");
				write("Leggo beast writes a letter.\n");
				say("Leggo beast coaxes: please, bring this back for me.\n");
				write("Leggo beast coaxes: please, bring this back for me.\n");
				letter->set_read( 
	"Dear Q172,\n (lots of unreadable text)\n love, Leggo\n" );
				letter->set_alias("letter2172");
				init_command("give "+what+" to "+lower_case(who));
				return 0;
			}
		}
		say("Leggo beast whispers something.\n");
		write("Leggo beast whispers something.\n");
	}
}

