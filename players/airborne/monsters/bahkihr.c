inherit "/obj/monster";
object scimitar;

reset(arg){
	::reset(arg);
    if(!arg) {
	set_name("bahkihr");
	set_level(20);
        set_gender(1); // str to int moonie 160893
	set_alias("warlock");
	set_al(-110);
	set_race("human");
	set_short("Bahkir the Warlock");
	set_long("Bahkihr as-Quatan is a desert man.  Master of Earth and\n"
		+"Air.  Beware his mighty wrath!\n");
	set_wc(10);
	set_aggressive(1);
	  load_chat(8, ({
		"Bahkihr says: I am the master if earth and air.\n",
		"Bahkihr says: Fight them big brothers!\n" }));
	set_dead_ob(this_object());
	set_spell_mess1("You feel the power of a ball lightning!\n");
	set_spell_mess2("Earth strikes you body.\n");
	set_chance(50);
	set_spell_dam(20);
  scimitar=clone_object("/players/airborne/weapons/scimitar");
   move_object(scimitar, this_object());
   init_command("wield sword");
	set_ac(10);
}
}
monster_died(ob) {
	write("You killed him.\n");
	return 0;
}
