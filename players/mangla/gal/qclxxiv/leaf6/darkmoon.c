#include "/players/qclxxiv/mymonster.h"
object mail;
reset(arg) {
	::reset(arg);
	if (arg) return;
	load_chat(10,({ 
"Darkmoon says: say who the hell ar you???? :)\n",
"Darkmoon falls down laughing.\n",
"Darkmoon says: mail me on Arg\n",
"Darkmoon giggles inanely.\n",
"Darkmoon grins evilly.\n",
"Darkmoon says: wizards keep zapping me\n",
"Darkmoon says: they ar morons\n",
"Darkmoon says: I'm a wizard on another mud under the name Aviston.\n",
"Darkmoon says: I'm also known as Imix amongst many others. <grin>\n",
"Darkmoon says: who the heck are you??I;m on arg now..come tell me :)\n",
"Darkmoon says: uhh...... ????  umm....  oh ...yes.   DUH!\n",
	}));
	load_a_chat(10,({ 
"Darkmoon says: duh.\n",
"Darkmoon says: DUH!\n",
"Darkmoon grins evilly.\n",
"Darkmoon giggles inanely.\n",
"Darkmoon says: I'll kill you you moron....DUH!.\n",
"Darkmoon says: I'll fight you under the table.   duh.\n",
"Darkmoon says: Duh. I'm a mighty wiz on other muds and kill you everywhere!\n",
	}));
	set_name("darkmoon");
	set_race("skum");
	set_level(22);
   	set_wc(20);
	set_ac(10);
   	set_hp(1186);
	set_sp(100);
   	set_spell_mess1("Darkmoon bites his opponent.");
   	set_spell_mess2("Darkmoon bites you.");
	set_chance(10);
	set_spell_dam(40);
	set_al(-20);
    load_match(this_object(), ({ "follow",  ({"leaves",}),
								 "receive", ({"gives",}),
						 		 "greet", ({"arrives",}),
								 "answer", ({"says", "tells you",}),
							 }));
   	set_aggressive(0);
   	set_short("Darkmoon");
	set_gender(1);
   	set_long(
"An ugly little creature, looking somewhat like a human. It seems to be weak\n"+
"but the skum is really rather dangerous, and is a notorious player-killer!\n");
	set_size(2);
	PLACE_IN_THIS(mail,HOME+"leaf6/skummail");
	init_command("wear mail"); 
}

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2) {
   		set_aggressive(1);
		command(where);
		/* init_command(where); */
	}
}

notify(str) {
    say(str);
    write(str);
}

receive(str) {
	string who, what;
	if(sscanf(str,"%s gives you %s.\n",who,what)==2) {
		notify("Darkmoon says: Thank you for the "+what+", "+who+", <grin>\n");
   		set_aggressive(1);
	}
}

greet(str) {
    string who, rest;
    if (sscanf(str, "%s arrives %s", who, rest) >= 1) {
    	notify("Darkmoon says: Hi "+who+".\n");
   		set_aggressive(0);
    }
}

answer(str) {
    string who, rest, message;
    sscanf(str, "%s %s", who, rest);
    if (lower_case(who)=="darkmoon") return;
    if (!( (sscanf(str, "%s says: %s\n", who, message) == 2) 
		|| (sscanf(str, "%s tells you: %s\n", who, message)==2)) ) {
       return;
    }
	notify("Darkmoon says: DUH!\n");
}

monster_died() {
	notify("Darkmoon rattles: I'll ......be....b....bbbback.. \n");
}

