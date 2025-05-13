inherit "/obj/monster";

reset(arg){
	::reset(arg);
	if(arg) return 1;
	set_name("air elemental");
	set_alias("air");
	set_alt_name("elemental");
	set_race("elmental");
	set_level(15);
	set_ac(3);
	set_wc(23);
	set_short("Air elemental");
	set_long("You see a shimmer  of greenish gas in front of you.\n"
		+ "The eyes glow a mysterious yellow. It does not look happy.\n");
	set_aggressive(1);
	set_whimpy();
	set_frog();
   set_chance(10);
   set_spell_dam(10);
   set_spell_mess1("The wind hits you with amazing force.\n");
   set_spell_mess2("The Air elemental throws balls of force.\n");
   return 1;
}
