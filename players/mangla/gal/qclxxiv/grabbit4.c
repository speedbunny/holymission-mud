inherit "players/qclxxiv/mymonster";
object spliff;
reset(arg) {
        ::reset(arg);
	 if (arg) return;
	 load_chat(10,({
		"tjeep.\n",
		"tjeep tjeeep.\n",
		"tjeeep   hey bastard!\n",
		"why you look so imbecil??? wrrrrrrt.\n",  /* <<< maybe , is essential*/
	  }));
	 load_a_chat(10,({
        "GGGGGGRRRRRROOOOOAAAAAAAAAAAAARRRRRRRRRRRRR.\n",
        "I'll bite of your head.\n",
        "I'm gonna stamp you to pulp.\n",
        "I'll have your limbs tonight for supper.\n",
	  }));
	set_name("grabbit");
	set_alias("huge grabbit");
	set_level(12);
   	set_wc(15);
	set_ac(10);
   	set_hp(426);
	set_sp(100);
   	set_spell_mess1("Grabbit grabs at its attackers limbs.");
   	set_spell_mess2("Grabbit grabs at your limbs.");
	set_chance(15);
	set_spell_dam(17);
    set_al(-400);
   	set_aggressive(0);
   	set_short("A tough, huge grabbit");
   	set_long("A tough, huge grabbit sneeking around your feet.\n");
	if (!spliff)
	{
		spliff=clone_object("/players/qclxxiv/spliff");
		move_object(spliff,this_object());
    	add_money(random(1200));
	}
    add_money(random(120));
	set_move_at_reset(0);
}

