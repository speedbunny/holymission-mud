#include "/players/qclxxiv/mymonster.h"
object scratcher,helmet;
reset(arg) {
	::reset(arg);
	if (arg) return;
	load_chat(10,({ 
"Timmy says: I am the mighty Timmy. Smarter than everyone.\n",
"Timmy falls down laughing. He pukes on his clothes.\n",
"Timmy says: I am an experienced wizard on MANY muds.\n",
"Timmy giggles insanely.\n",
"Timmy grins pathetically.\n",
"Timmy says: I'm smarter than all the wizes on this mud!\n",
"Timmy says: Man am I smart.\n",
"Timmy says: I am the mysterious Darkmoon, the super player-killer.\n",
"Timmy says: I'm a wizard on another mud under the name Aviston.\n",
"Timmy says: I'm also known as Imix amongst many others. <grin>\n",
"Timmy's mother shouts: Timmy come and have your supper!\n",
"Timmy's mother shouts: And don't forget we are going to aunty Ann tonight!\n",
	}));
	load_a_chat(10,({ 
"Timmy says: duh.\n",
"Timmy says: DUH! I AM THE MIGHTY TIMMY  YOU FOOL!\n",
"Timmy grins pathetically.\n",
"Timmy giggles insanely.\n",
"Timmy says: I'll kill you you moron....DUH!. I'll call my daddy now!\n",
"Timmy says: I'll fight you under the table.   duh.\n",
"Timmy says: Duh. I'm a mighty wiz on other muds and kill you everywhere!\n",
	}));
	set_name("timmy");
	set_race("skum");
	set_level(22);
   	set_wc(16);
	set_ac(7);
   	set_hp(1200);
	set_sp(70);
   	set_spell_mess1("Timmy pulls his attacker's hair.");
   	set_spell_mess2("Timmy pulls your hair.");
	set_chance(20);
	set_spell_dam(20);
	set_al(-20);
    load_match(this_object(), ({ "follow",  ({"leaves",}),
								 "receive", ({"gives",}),
						 		 "greet", ({"arrives",}),
								 "answer", ({"says", "tells you",}),
							 }));
   	set_aggressive(0);
   	set_short("Timmy");
	set_gender(1);
   	set_long(
"An ugly pimply boy, about 19 years old, picking his nose. He looks nasty.\n"+
"Be careful not to turn your back to him! It's just the type to stab people\n"+
"in the back.\n" );
	set_size(1);
	PLACE_IN_THIS(scratcher,HOME+"leaf6/scratcher");
	PLACE_IN_THIS(helmet,HOME+"leaf6/skumhelmet");
	init_command("wear helmet"); 
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
		notify("Timmy says: Thank you for the "+what+", "+who+", <grin>\n");
   		set_aggressive(1);
	}
}

greet(str) {
    string who, rest;
    if (sscanf(str, "%s arrives %s", who, rest) >= 1) {
    	notify("Timmy says: Hi "+who+".\n");
   		set_aggressive(0);
    }
}

answer(str) {
    string who, rest, message;
    sscanf(str, "%s %s", who, rest);
    if (lower_case(who)=="timmy") return;
    if (!( (sscanf(str, "%s says: %s\n", who, message) == 2) 
		|| (sscanf(str, "%s tells you: %s\n", who, message)==2)) ) {
       return;
    }
	notify("Timmy says: DUH!\n");
}

monster_died() {
	notify("Timmy rattles: dd...d...uu.h. \n");
}

