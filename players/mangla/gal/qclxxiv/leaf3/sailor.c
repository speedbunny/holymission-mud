inherit "players/qclxxiv/mymonster";
object diagnoser;
reset(arg) {
        ::reset(arg);
	 if (arg) return;
	 load_chat(35,({
		"Sailor says: Go away!\n",
		"HAAAAAAAAAAACHOOOO. Sailor sneezes moisty.\n",
		"Sailor says: Don't come near me!\n",
		"HAAAAAAAAAAACHOOOO. Sailor sneezes moisty.\n",
		"Sailor says: UGH UGH UGH...I've caught mongolian flu!\n",
		"UGH UGH UGH. Sailor coughs nastily.\n",
	  }));
	set_name("sailor");
	set_level(12);
   	set_wc(16);
	set_ac(9);
   	set_hp(800);
	set_sp(100);
   	set_spell_mess1("Sailor coughs in his attacker's direction.");
   	set_spell_mess2("Sailor coughs in your direction.");
	set_chance(35);
	set_spell_dam(20);
    set_al(0);
   	set_aggressive(0);
   	set_short("A sailor");
   	set_long("A sailor, looking quite pale and ill.\n");
    add_money(random(40));
}

