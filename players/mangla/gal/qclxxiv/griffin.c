inherit "players/qclxxiv/mymonster";

reset(arg) {
  object cx, griftail;
        ::reset(arg);
	 if (arg) return;
	 load_chat(20,({
		"Water drips from the corners of Griffin's big mouth.\n",
		"Will the Griffin feed itself with you, a tiny little adventurer?\n",
		"GrrrrrrrrFFfrrrrrrtffff.\n",
		"The Griffin looks hungry.\n",
		"Grffffffrrrrrrttttt.\n",
		"You hear a deep rumbling sound coming from the Griffin's stomach....\n"
	  }));
	 load_a_chat(30,({
        "You wanted this yourself fool.\n",
        "You are gonna regret you ever came here.\n",
        "The Griffin drips slime on you as he tries to spit fire.\n",
	  }));
    /* load_match(this_object(), ({ "follow",  ({"leaves",}),})); */
	set_name("griffin");
	set_race("dragon");
	set_level(30);
   	set_wc(23);
	set_ac(25);
   	set_hp(5000);
	set_sp(200);
   	set_spell_mess1("Griffin curls it's tail around its opponent's legs.");
   	set_spell_mess2("Griffin curls it's tail around your legs.");
	set_chance(25);
	set_spell_dam(35);
    set_al(-50);
   	set_aggressive(1);
   	set_short("A Griffin");
   	set_long("A legendary Griffin staring at you strangely.\n"+
			"Better not attack it when you have still a low level!\n" );
	set_gender(0);
	set_size(5);
    /* set_whimpy(); */
	/* set_move_at_reset(0); */
    cx=clone_object("/obj/treasure");
    cx->set_id("stone");
    cx->set_short("A Griffin's stone");
    cx->set_long("A Griffin's stone, useless but not without value.\n");
    cx->set_value(500);
    move_object(cx,this_object());
    griftail=clone_object("obj/weapon");
    griftail->set_id("tail");
    griftail->set_class(19);
    griftail->set_weight(3);
    griftail->set_value(3700);
    griftail->set_short("Griffin's tail");
    griftail->set_long("The powerful Griffin's tail. It looks valueable.\n");
    move_object(griftail,this_object());
	command("wield tail",this_object());
}

/*
follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
		if (random(3)==2)
			init_command(where);
}
*/

