inherit "players/qclxxiv/mymonster";

reset(arg) {
  string chats,a_chats;
  object tshirt;
	::reset(arg);
    if (!chats) {
		chats = allocate(9);
		chats[0] = "Junkie says: Well this sure is a nice machine...\n";
		chats[1] = 
	"Junkie says: It's really fair to ALL players, ask any wiz to check.\n";
		chats[8] = "Junkie says: They had me go to speech therapy now...%.\n";
		chats[2] = "Junkie says: It pays out around 100 %.\n";
		chats[3] = "Junkie says: Jackpot means 20,000 coins!!!\n";
		chats[4] = "Junkie says: Man, how I wish I had 100 coins to play...\n";
		chats[5] = "Junkie says: It could give jackpot any play now..\n";
		chats[6] = "Junkie says: Can you not spare me a 100 coins?\n";
		chats[7] = 
"It's said that these silver 100 coin pieces make it hang at jackpot...\n";
    }
    if (!a_chats) {
        a_chats = allocate(4);
        a_chats[0] = 
	"Junkie shouts: You ungrateful bastard!\n";
        a_chats[1] = 
	"Junkie says: Consider how much I could have helped you playing...\n";
        a_chats[2] = 
	"Junkie says: I'll tell this to Q man, he's a friend of mine.\n";
        a_chats[3] = 
	"Junkie warns: Look!!!  behind you!   aaaaaarrrrrrgggh......\n";
    }
	if (arg) return;
	set_name("junkie");
	set_alias("junk");
	set_level(7);
   	set_wc(8);
   	set_hp(200);
	/* set_ep(1000); */
	set_sp(75);
   	set_spell_mess1("The jackpot junkie pokes his opponent in the eye.");
   	set_spell_mess2("The jackpot junkie pokes in your eye.");
	set_chance(25);
	set_spell_dam(7);
    set_al(0);
	load_chat(25,chats);
	load_a_chat(25,a_chats);
    load_match(this_object(), ({ "receive", ({"gives",}), 
								"answer", ({"mines",}),
								 "dosmile", ({"just",}), 
								}));
						/*		 "maybeplay", ({"rolls",}),  */
   	set_aggressive(0);
   	set_short("A jackpot junkie");
   	set_long(
"A pityful jackpot junkie, spending his days and dimes on the machine.\n"+
"He could give you valuable advises when playing of course, as he knows\n"+
"this machine as no one else. The poor addict is broke again today.\n" );
	enable_commands();
	set_living_name("junkie");
	tshirt=clone_object("/players/qclxxiv/tshirt");
	move_object(tshirt,this_object());
	command("wear shirt",this_object());
}
		
notify(str) {
    say("Jackjunk says: "+str);
    write("Jackjunk says: "+str);
}

play() {
	/*jackpot seems not able to take junkies money, so: */
	if ( query_money() >= 100 && query_money() < 20000 )
	{
		init_command("play jackpot");
		call_out("play",1);
		/* money -= 100; */
	}
}

maybeplay(str) {
	string hop;
    if(sscanf(str, "The rolls stop %s", hop) >= 1) {
		if ( query_money() >= 100 && query_money() < 20000 )
			play();
	}
}

dosmile(str) {
	int price;
	if(sscanf(str,"You just won %d coins.\n",price)==1)
		init_command("smile");
}

receive(str) {
	string who, what;
	if(sscanf(str,"%s gives you %s.\n",who,what)==2)
		notify("Thank you for the "+what+", "+who+"!\n");
	if ( query_money() >= 100 )
		play();
}

answer(str) {
    string who, lwho, rest, message; 
    sscanf(str, "%s %s", who, rest);
	lwho = lower_case(who);
    if (lwho=="jackjunk") return;
    if (!( sscanf(rest, "says: %s\n", message) 
		|| sscanf(rest, "tells you: %s\n", message) ) ) return;
	message = " " + lower_case(message) + " ."; /* add stuff for easier parse*/
	answer_anyone(who, message);
}

answer_anyone(who, message) {
	string dum;
	if (sscanf(message,"%s mines", dum)) {
		notify(
"How would I know about mines? Ask the beggar for that matter\n");
		return;
	}
}


