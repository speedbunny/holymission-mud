inherit "players/qclxxiv/mymonster";
object claws;
reset(arg) {
        ::reset(arg);
	 if (arg) return;
	 load_chat(10,({
		"meep.\n",
		"meep meeep.\n",
		"meeep   hey newbie!.\n",
		"why you look so stupid??? mrrrrrrt.\n",  /* <<< maybe , is essential*/
	  }));
	 load_a_chat(10,({
        "GROAAAaaarrrrrr.\n",
        "I'll bite of your nose.\n",
        "I'm gonna grab your eyes, bastard.\n",
        "I'll eat your bowels.\n",
	  }));
    load_match(this_object(), ({ "follow",  ({"leaves",}),}));
	set_name("grabbit");
	set_alias("medium large grabbit");
	set_level(4);
   	set_wc(9);
	set_ac(4);
   	set_hp(106);
	set_ep(23000); 
	set_sp(55);
   	set_spell_mess1("Grabbit grabs at its attackers bowels.");
   	set_spell_mess2("Grabbit grabs at your bowels.");
	set_chance(35);
	set_spell_dam(7);
    set_al(-100);
   	set_aggressive(0);
   	set_short("A tough, medium large grabbit");
   	set_long("A tough, medium large grabbit sneeking around your feet.\n");
	if (!claws)
	{
		claws=clone_object("/players/qclxxiv/mgclaws");
		move_object(claws,this_object());
    	add_money(random(400));
	}
    add_money(random(40));
    set_whimpy(20);
	set_move_at_reset(0);
}

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
		if (who!="Grabbit" && random(10)>7) command(where);
		/*if (who!="Grabbit" && random(10)>7) init_command(where);*/
}

