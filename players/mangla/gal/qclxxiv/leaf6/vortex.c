#include "/players/qclxxiv/mymonster.h"
object sword;
reset(arg) {
	::reset(arg);
	if (arg) return;
	load_chat(10,({ 
"Vortex shouts: whats the last address of llaurasia? its not on any lists\n",
"Darkmoon shouts: 128.2.29.128 3000\n",
"Vortex says: the wizzes here snoop me all the time...\n",
"Vortex says: they're SO smart\n",
"Vortex spits on the ground.\n",
"Vortex says: i'm going to crush them all methinks\n",
"Vortex shouts: Darkmoon. you still pk-ing?\n",
"Vortex grins evilly.\n",
"Vortex says: they sure are morons.\n",
"Vortex says: prove to me you're darkmoon. whasts you're other name...\n",
"Vortex says: the one that begins with A\n",
"Vortex says: just making sure, the wizzes are trying to remove all my aliases on here\n",
"Vortex says: and i really want to wiz with one of them, so i can screw them over\n",
"Vortex says: ok, but i'm on a shit computer, have to leave this one.\n",
	}));
	load_a_chat(10,({ 
"Vortex says: shit!\n",
"Vortex grins evilly.\n",
"Vortex says: i'm going to crush you now methinks\n",
"Vortex spits on the ground.\n",
	}));
	set_name("vortex");
	set_race("skum");
	set_level(22);
   	set_wc(16);
	set_ac(7);
   	set_hp(1200);
	set_sp(100);
   	set_spell_mess1("Vortex spits his opponent in the face.");
   	set_spell_mess2("Vortex spits you in the face.");
	set_chance(13);
	set_spell_dam(30);
	set_al(-20);
    load_match(this_object(), ({ "follow",  ({"leaves",}),
								 "receive", ({"gives",}),
						 		 "greet", ({"arrives",}),
								 "answer", ({"says", "tells you",}),
							 }));
   	set_aggressive(0);
   	set_short("Vortex");
	set_gender(1);
   	set_long(
"A stinking something that only vaguely resembles a human being. The smell\n"+
"makes you feel like you're going to vomit. This skum makes a habit of it\n"+
"to attack and kill low-level players, preferably total newbies.\n" );
	set_size(3);
	PLACE_IN_THIS(sword,HOME+"leaf6/skumsword");
	/* init_command("wield sword");  */
}

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2) {
   		set_aggressive(1);
		command(where);
		/*init_command(where);*/
	}
}

notify(str) {
    say(str);
    write(str);
}

receive(str) {
	string who, what;
	if(sscanf(str,"%s gives you %s.\n",who,what)==2) {
		notify("Vortex says: Thank you for the "+what+", "+who+", <grin>\n");
   		set_aggressive(1);
	}
}

greet(str) {
    string who, rest;
    if (sscanf(str, "%s arrives %s", who, rest) >= 1) {
    	notify("Vortex says: hello.\n");
		notify("Vortex spits on the floor.\n");
   		set_aggressive(0);
    }
}

answer(str) {
    string who, rest, message;
    sscanf(str, "%s %s", who, rest);
    if (lower_case(who)=="vortex") return;
    if (!( (sscanf(str, "%s says: %s\n", who, message) == 2) 
		|| (sscanf(str, "%s tells you: %s\n", who, message)==2)) ) {
       return;
    }
	notify("Vortex says: shit!\n");
}

monster_died() {
	notify("Vortex rattles: I'll ......get....you fffffor t..ahh..... \n");
}

