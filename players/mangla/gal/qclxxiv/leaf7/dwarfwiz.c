inherit "players/qclxxiv/mymonster";
#define PLACE_IN_THIS(OBJNAME, FILNAME)\
OBJNAME = place_in_this(OBJNAME,FILNAME,this_object());

reset(arg) {
  object wand, amulet;
        ::reset(arg);
	 if (arg) return;
	 load_chat(10,({
		"You hear a soft twittering...\n",
		"Was that a dwarf you saw moving there?\n",
		"Was that a dwarf you saw moving there?\n",
		"Was that a dwarf you saw moving there?\n",
		"Was that a dwarf you saw moving there?\n",
		"Was that a dwarf you saw moving there?\n",
		". moves around\n"
	  }));
	 load_a_chat(30,({
        "The dwarfwizard utters angry curses.\n",
	  }));
	set_name("dwarf");
	set_alias("dwarfwizard"); 
	set_level(13);
   	set_wc(8);	/* Has also a very high spell change */
	set_ac(14);
   	set_hp(484);
	set_sp(100);
   	set_spell_mess1(
		"The dwarfwizard casts a spell and cruches one of his opponents toes.");
   	set_spell_mess2(
		"The dwarfwizard casts a spell and cruches one of your toes.");
	set_chance(50);
	set_spell_dam(10);
    set_al(-100);
   	set_aggressive(0);
   	set_short("");
   	set_long("You peer at the tiny dot that you suspect to be a dwarf,\n"+
			"it appears to be the dwarfwizard. Be careful! spells have\n"+
			"nothing to do with size...\n");
    /* set_whimpy(); */
    amulet=clone_object("/obj/armour");
    amulet->set_id("amulet");
    amulet->set_short("An onyx amulet");
    amulet->set_long("An onyx amulet, normally carried by dwarfwizards.\n");
	amulet->set_type("amulet");
    amulet->set_value(100);
    move_object(amulet,this_object());
    wand=clone_object("obj/weapon");
    wand->set_id("wand");
    wand->set_class(11);
    wand->set_weight(0);
    wand->set_value(100);
    wand->set_short("A dwarfwizard's wand");
    wand->set_long("A dwarfwizard's wand, set with small amethysts.\n");
    move_object(wand,this_object());
	command("wield wand",this_object());
}

second_life() {
	object loot1, loot2;
	if ("/players/qclxxiv/qquest/qmast"->lock_name2key(1,
			this_player()->query_real_name())==7) {
		PLACE_IN_THIS(loot1,"/players/qclxxiv/qquest/map1");
		loot1->setup_map(this_player());
		PLACE_IN_THIS(loot2,"/players/qclxxiv/qquest/fearstone");
		log_file("qmap",this_player()->query_real_name()+" map1 "+
				ctime(time())+"\n");
		write_file("/players/qclxxiv/qquest/qmap",
				this_player()->query_real_name()+" map1 "+ctime(time())+"\n");
	}
	return 0;
}

