	inherit "obj/monster";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("eel");
	set_alias("eel");
	set_race("fish");
	set_short("Sea eel");
	set_long("Long sea eel slides around you. You never seen longer eel.\n");
	set_al(-20);
	set_level(33);
	set_has_gills();
	set_size(2);
	set_aggressive(0);
	set_spell_mess2("You feel hard electric shock on your feet.\n");
	set_spell_mess1("Long eel makes hit with its electric teeth !\n");
	set_chance(45);
	set_spell_dam(random(80));
}
