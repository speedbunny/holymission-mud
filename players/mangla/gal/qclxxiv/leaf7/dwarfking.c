inherit "players/qclxxiv/mymonster";

reset(arg) {
  object coin, sword;
        ::reset(arg);
	 if (arg) return;
	 load_chat(7,({
		"You hear a soft twittering...\n",
		"You hear a soft twittering...\n",
		"Was that a dwarf you saw moving there?\n",
		"Was that a dwarf you saw moving there?\n",
		"Was that a dwarf you saw moving there?\n",
		"Was that a dwarf you saw moving there?\n",
		". moves around\n"
	  }));
	 load_a_chat(30,({
		"The dwarfking says: I'm a king you idiot!\n",
        "The dwarfking utters angry curses.\n",
	  }));
	set_name("dwarf");
	set_alias("dwarfking"); 
	set_level(12);
   	set_wc(12);
	set_ac(4);
   	set_hp(426);
	set_sp(80);
   	set_spell_mess1( "The dwarfking curses his enemy.");
   	set_spell_mess2( "The dwarfking curses you.");
	set_chance(37);
	set_spell_dam(7);
    set_al(-70);
   	set_aggressive(0);
   	set_short("");
   	set_long("You peer at the tiny dot that you suspect to be a dwarf,\n"+
			"it appears to be the dwarfking. He's tiny but impressive .\n");
    /* set_whimpy(); */
    coin=clone_object("/players/qclxxiv/obj/scoin");
    move_object(coin,this_object());
    sword=clone_object("obj/weapon");
    sword->set_id("sword");
    sword->set_class(12);
    sword->set_weight(0);
	sword->set_size(1);
    sword->set_value(700);
    sword->set_short("A dwarfkings's sword");
    sword->set_long("A dwarfking's sword, small but impressive.\n");
    move_object(sword,this_object());
	command("wield sword",this_object());
}

