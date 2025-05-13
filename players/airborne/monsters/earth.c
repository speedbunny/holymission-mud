inherit "/obj/monster";

reset(arg){
	::reset(arg);
	if(arg) return 1;
	set_name("earth elemental");
	set_alias("earth");
	set_alt_name("elemental");
	set_race("elmental");
	set_level(15);
	set_ac(12);
	set_wc(7);
	set_short("Earth Elemental");
	set_long("A moving pile of sand and stone.\n");
	set_aggressive(1);
	set_frog();
   set_chance(10);
   set_spell_dam(25);
   set_spell_mess1("He clushes you with a mighty blow!\n");
   set_spell_mess2("Elemental tries to turn you to clay.\n");
   return 1;
}
