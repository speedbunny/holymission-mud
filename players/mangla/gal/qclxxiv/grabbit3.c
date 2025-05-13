inherit "players/qclxxiv/mymonster";
object claws;
reset(arg) {
        ::reset(arg);
	 if (arg) return;
	 load_chat(10,({
		"njeep.\n",
		"njeep njeeep.\n",
		"njeeep   hey green one!.\n",
		"why you look so idiotic??? frrrrrrt.\n",  /* <<< maybe , is essential*/
	  }));
	 load_a_chat(10,({
        "GROAAAAAARRRRRR.\n",
        "I'll bite of your fingers.\n",
        "I'm gonna trash you to pieces.\n",
        "I'll eat your idiotic head tonight for dessert.\n",
	  }));
    load_match(this_object(), ({ "follow",  ({"leaves",}),}));
	set_name("grabbit");
	set_alias("large grabbit");
	set_level(6);
   	set_wc(12);
	set_ac(6);
   	set_hp(162);
	set_ep(50000); 
	set_sp(75);
   	set_spell_mess1("Grabbit bites its attacker in the fingers.");
   	set_spell_mess2("Grabbit bites you in your fingers.");
	set_chance(25);
	set_spell_dam(11);
    set_al(-200);
   	set_aggressive(0);
   	set_short("A tough, large grabbit");
   	set_long("A tough, large grabbit sneeking around your feet.\n");
	if (!claws)
	{
		claws=clone_object("/players/qclxxiv/gclaws");
		move_object(claws,this_object());
    	add_money(random(600));
	}
    add_money(random(60));
	set_move_at_reset(0);
}

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
		if (who!="Grabbit" && random(10)>7) command(where);
		/*if (who!="Grabbit" && random(10)>7) init_command(where);*/
}

