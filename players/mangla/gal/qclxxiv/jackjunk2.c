inherit "players/qclxxiv/mymonster";

reset(arg) {
  string chats,a_chats;
  object tshirt;
	::reset(arg);
    if (!chats) {
		chats = allocate(11);
		chats[0] = "Junkie says: Well they have nice machines there...\n";
		chats[1] = 
	"Junkie says: ....really fair to ALL players, ask any wiz to check.\n";
		chats[10] = "Junkie says: They had me go to speech therapy now....\n";
		chats[2] = "Junkie says: They pays out around 100 %.\n";
		chats[3] = "Junkie says: Jackpot means 20,000 coins!!!\n";
		chats[4] = "Junkie says: Man, how I wish I had 100 coins to play...\n";
		chats[5] = "Junkie says: Qclxxiv's Giant Leaf is northeast on large open plane..\n";
		chats[6] = "Junkie says: Can you not spare me a 100 coins?\n";
		chats[7] = 
"It's said that these light silver 100 coin pieces hangup the jackpots...\n";
		chats[8] = "Now they also have that Luxury Shop thing there.\nI'd say it's more like a utility shop in between..\n";
		chats[9] = "I have had those complaints about me language you know.\n";
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
	set_level(5);
   	set_wc(7);
   	set_hp(132);
	/* set_ep(1000); */
	set_sp(75);
   	set_spell_mess1("The jackpot junkie pokes his opponent in the eye.");
   	set_spell_mess2("The jackpot junkie pokes in your eye.");
	set_chance(80);
	set_spell_dam(5);
    set_al(0);
	load_chat(25,chats);
	load_a_chat(25,a_chats);
    load_match(this_object(), ({ "follow",  ({"leaves",}),
								 "receive", ({"gives",}), }));
   	set_aggressive(0);
   	set_short("A jackpot junkie");
   	set_long(
"A pityful jackpot junkie, spending his days and dimes on the machine.\n"+
"He could give you valuable advises on playing of course.\n"+
"The poor addict is broke again today, so he's begging around in town.\n" );
	tshirt=clone_object("/players/qclxxiv/tshirt");
	move_object(tshirt,this_object());
	command("wear shirt",this_object());
}
		
notify(str) {
    say(str);
    write(str);
}

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
			init_command(where);
}

receive(str) {
	string who, what;
	if(sscanf(str,"%s gives you %s.\n",who,what)==2)
		notify("Thank you for the "+what+", "+who+"!\n");
}
