inherit "players/qclxxiv/mymonster";
object shield;
reset(arg) {
        ::reset(arg);
	 if (arg) return;
	 load_chat(10,({
		"zeep.\n",
		"zeep zeeep.\n",
		"zeeep   hey moron!.\n",
		"why you look so moronic??? wrrrrrrt.\n",  /* <<< maybe , is essential*/
	  }));
	 load_a_chat(10,({
        "XXXXXSSSS....GGGGGGRRRRRROOOOOAAAAAAAAAAAAAUUUUUUUUURRRRRRRRRRRRR.\n",
        "I'll swallow you alive.\n",
        "I'm gonna zap you.\n",
        "I'll fill the hole in my tooth with you moronic dwarf!.\n",
	  }));
	set_name("grabbit");
	set_alias("giant grabbit");
	set_level(20);
   	set_wc(20);
	set_ac(6);
   	set_hp(1010);
	set_sp(170);
   	set_spell_mess1("Grabbit smashes its attacker against the floor.");
   	set_spell_mess2("Grabbit smashes you against the floor.");
	set_chance(10);
	set_spell_dam(27);
    set_al(-600);
   	set_aggressive(0);
   	set_short("A tough, Giant grabbit");
   	set_long("A tough, Giant grabbit facing you with its ugly face.\n");
	if (!shield)
	{
		shield=clone_object("/players/qclxxiv/obj/gr5shield");
		move_object(shield,this_object());
		command("wear shield",this_object());
    	add_money(random(1700));
	}
    add_money(random(170));
	set_move_at_reset(0);
}

