inherit "players/qclxxiv/mymonster";

reset(arg) {
  object wand;
        ::reset(arg);
	 if (arg) return;
	 load_chat(20,({
"Q173 says: Let me give you a golden hint: Q172 hides in a machine in the\n"
+"circular room. You can pay me back by giving the beggar 10 coins.\n",
		"Q173 says: Check out that nice pub in the fishing village!\n",
		"Q173 says: Well...Q174 is a worthy follower.\n",
		"Q173 says: Experimenting all the time, you know those youths.\n",
		"Q173 says: He makes lots of mistakes...too heavy weapons...\n"+
		"too big exp gain...\n",
"Q173 says: It is said that Q172 hides in one of those machines in the\n"
+"circular room.\n",
		"Q173 says: Not to mention the too strong or too weak monsters....\n",
		"Q173 says: Well I guess he'll learn.\n",
"Q173 says: Let me give you a golden hint: Q172 hides in a machine in the\n"
+"circular room. You can pay me back by giving the beggar 10 coins.\n",
	"Q173 says: Young Q174 does place weird things into the castle though.\n",
		"Q173 says: What to think of for instance this silly jackpot.\n",
		"Q173 says: I personally do not like these newfangled caprices.\n",
"Q173 says: It is said that Q172 hides in one of those machines in the\n"
+"circular room.\n",
	  }));
	 load_a_chat(20,({
        "Q173 tries to hypnotize you, you feel disoriented.\n",
        "Q173 tries to cast some spell, you wonder if he succeeded or not...\n",
        "Q173 shouts: did you think GHOSTS of wizards where NOT harmful?\n",
        "Q173 waves his wand and.......nothing seems to happen.\n",
        "Q173 stares intensively at your legs.\n",
	  }));
	set_name("q173");
	set_alias("ghost"); 
	set_level(30);
	/* wc lower than default (and ac higher) because: */
	/* should not kill easy   but also not be easily killed */
	/* and should stay at his position */
   	set_wc(20);		
	set_ac(20);	
   	set_hp(2082);
	set_sp(200);
   	set_spell_mess1(
    "Ghost of Q173 waves his wand and hop there goes his opponent's left arm.");
   	set_spell_mess2(
        "Ghost of Q173 waves his wand and hop there goes your left arm.");
	set_chance(35);
	set_spell_dam(24);
    set_al(100);
	set_gender(1);
    load_match(this_object(), ({ 
								"answer", ({"mines",}),
								}) );
   	set_aggressive(0);
   	set_short("Ghost of Q173");
   	set_long("The ghost of Q173, Q174's predecessor.\n");
    set_whimpy();
    wand=clone_object("obj/weapon");
    wand->set_id("wand");
    wand->set_class(15);
    wand->set_weight(1);
    wand->set_value(700);
    wand->set_short("Q173's Wand of Wizards (burning) ");
    move_object(wand,this_object());
	command("wield wand",this_object());
}

say_room(str) {   /* NOT to be called from actions */
    say("Q173 says: "+str); /* to all in room BUT vendor. */
}

answer(str) {
    string who, lwho, rest, message; 
    sscanf(str, "%s %s", who, rest);
	lwho = lower_case(who);
    if (lwho=="ghost") return;
    if (!( sscanf(rest, "says: %s\n", message) 
		|| sscanf(rest, "tells you: %s\n", message) ) ) return;
	message = " " + lower_case(message) + " ."; /* add stuff for easier parse*/
	answer_anyone(who, message);
}

answer_anyone(who, message) {
	string dum;
	if (sscanf(message,"%s mines", dum)) {
		say_room("The librarian knows a lot about mines, I think\n");
		return;
	}
}

