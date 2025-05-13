inherit "players/qclxxiv/mymonster";
reset(arg) {
        ::reset(arg);
	 if (arg) return;
	 load_a_chat(15,({
        "Dykeghost says: You shouldn't have disturbed me.\n",
        "Dykeghost says: Why did you have to bother me.\n",
        "Dykeghost says: Who did you think you could fool?\n",
	  }));
	set_name("ghost");
	set_alias("dykeghost");
	set_level(14);
   	set_wc(18);
	set_ac(10);
   	set_hp(700);
	set_sp(55);
   	set_spell_mess1("Dykeghost casts a spell on his opponent.");
   	set_spell_mess2("Dykeghost casts a spell on you.");
	set_chance(15);
	set_spell_dam(20);
    set_al(0);
   	set_aggressive(1);
   	set_short("A dykeghost");
   	set_long("A dykeghost, very big, and looking very angry.\n");
	call_out("selfdest", 40);
}

selfdest() { 
	if (this_object() && environment(this_object()))
		tell_room( environment(this_object()), 
					"Dykeghost disappears in a puff of smoke.\n");
	if (this_object())
		destruct(this_object()); 
}

