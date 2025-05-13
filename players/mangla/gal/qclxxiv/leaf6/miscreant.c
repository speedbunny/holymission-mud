#include "/players/qclxxiv/mymonster.h"
object mail;
reset(arg) {
	::reset(arg);
	if (!mail) { PLACE_IN_THIS(mail,HOME+"leaf6/malmail"); }
	if (arg) return;
	load_chat(15,({ 
"Malicious miscreant murmurs something unintelligibble.\n",
"Malicious miscreant looks at you.\n",
"Malicious miscreant walks up and down.\n",
"Malicious miscreant grins malevolently.\n",
"Malicious miscreant sighs.\n",
	}));
	load_a_chat(15,({ 
"Malicious miscreant spits at you.\n",
"Malicious miscreant tries to pull your hair.\n",
"Malicious miscreant kicks towards your knees.\n",
"Malicious miscreant murmurs a strange message. Nothing happens.\n",
	}));
	set_name("miscreant");
	set_alias("malicious miscreant");
	set_race("skum");
	set_level(32);
   	set_wc(22);
	set_ac(10);
   	set_hp(2500);
	set_sp(120);
   	set_spell_mess1(
		"Malicious miscreant gives its attacker one malicious BLOW.");
   	set_spell_mess2( "Malicious miscreant gives you one malicious BLOW.");
	set_chance(35);
	set_spell_dam(70);
	set_al(-29);
   	set_aggressive(0);
   	set_short("Malicious miscreant");
	set_gender(1);
   	set_long(
"Malicious miscreant is missing one eye. With the remaining one\n"+
"it eyes you meanly.\n" );
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
			if (sscanf(letter->query_text(),"%s Miscreant", dum)) {
				say("Malicious miscreant grumbles something.\n");
				write("Malicious miscreant grumbles something.\n");
				say("Malicious miscreant writes a letter.\n");
				write("Malicious miscreant writes a letter.\n");
				say("Malicious miscreant grunts: here, bring this back.\n");
				write("Malicious miscreant grunts: here, bring this back.\n");
				letter->set_read( 
	"Dear Q172,\n (lots of unreadable text)\n regards, Miscreant\n" );
				letter->set_alias("letter2172");
				init_command("give "+what+" to "+lower_case(who));
				return 0;
			}
		}
		say("Malicious miscreant grumbles something.\n");
		write("Malicious miscreant grumbles something.\n");
	}
}


