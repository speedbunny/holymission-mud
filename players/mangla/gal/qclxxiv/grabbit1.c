/* hopefully improved again, (last change made error such that grabbit2 did
// not even appear H).
*/
inherit "players/qclxxiv/mymonster";
object diagnoser;
reset(arg) {
        ::reset(arg);
	 if (arg) return;
	 load_chat(15,({
		"peep.\n",
		"peep peeep.\n",
		"peeep   hey newbie!.\n",
		"why you look so silly??? mrrrrrrt.\n",  /* <<< maybe , is essential*/
	  }));
	 load_a_chat(15,({
        "Groaaaaaarrrrrr.\n",
        "I'll bite of your ears.\n",
        "I'm gonna grab your heart, sucker.\n",
        "I'll scratch your face.\n",
	  }));
    load_match(this_object(), ({ "follow",  ({"leaves",}),}));
	set_name("grabbit");
	set_alias("not so little grabbit");
	set_level(3);
   	set_wc(8);
	set_ac(3);
   	set_hp(100);
	set_sp(55);
   	set_spell_mess1("Grabbit scratches its attackers face badly.");
   	set_spell_mess2("Grabbit scratches your face badly.");
	set_chance(45);
	set_spell_dam(5);
    set_al(-100);
   	set_aggressive(0);
   	set_short("A tough, not so little grabbit");
   	set_long("A tough, not so little grabbit sneeking around your feet.\n");
	if (!diagnoser)
	{
		diagnoser=clone_object("/players/qclxxiv/diag");
		move_object(diagnoser,this_object());
    	add_money(random(300));
	}
    add_money(random(30));
    set_whimpy();
	set_move_at_reset(0);
}

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
		if (who!="Grabbit" && random(10)>7) command(where);
		/*if (who!="Grabbit" && random(10)>7) init_command(where);*/
}

