#include "/players/qclxxiv/mymonster.h"
object jar;
reset(arg) {
	::reset(arg);
	if (!jar) {
		if (random(10)>4) {
			PLACE_IN_THIS(jar,HOME+"leaf6/healthjar");
		}
		else {
			PLACE_IN_THIS(jar,HOME+"leaf6/spelljar");
		}
	}
	if (arg) return;
	load_chat(10,({ 
"The horrible hag says: you look like a good meal to me.\n",
"The horrible hag laughs horribly.\n",
"The horrible hag starts walking around you.\n",
"The horrible hag giggles insanely.\n",
	}));
	load_a_chat(10,({ 
"The horrible hag shouts: I'll change you into a frog!.\n",
"The horrible hag scratches you in the face.\n",
"The horrible hag seems to be preparing a nasty spell.\n",
"The horrible hag takes a sip of her jar.\n",
	}));
	set_name("hag");
	set_race("skum");
	set_level(26);
   	set_wc(27);
	set_ac(10);
   	set_hp(1602);
	set_sp(90);
   	set_spell_mess1(
"The horrible hag hits her attacker with an invisible something.");
   	set_spell_mess2("The horrible hag hits you with an invisible something.");
	set_chance(30);
	set_spell_dam(40);
	set_al(-23);
   	set_aggressive(0);
   	set_short("A horrible hag");
	set_gender(2);
   	set_long("A horrible hag. She looks at you hungrily, and grins evilly.\n" );
	set_size(3);
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
			if (sscanf(letter->query_text(),"%s Hag", dum)) {
				say("The horrible hag grumbles something.\n");
				write("The horrible hag grumbles something.\n");
				say("The horrible hag writes a letter.\n");
				write("The horrible hag writes a letter.\n");
				say("The horrible hag grunts: here, bring this back.\n");
				write("The horrible hag grunts: here, bring this back.\n");
				letter->set_read( 
	"Dear Q172,\n (lots of unreadable text)\n regards, Haggie\n" );
				letter->set_alias("letter2172");
				init_command("give "+what+" to "+lower_case(who));
				return 0;
			}
		}
		say("The horrible hag grumbles something.\n");
		write("The horrible hag grumbles something.\n");
	}
}

