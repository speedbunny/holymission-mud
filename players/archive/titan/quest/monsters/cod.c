	inherit "obj/monster";

	reset(arg) {
	::reset(arg);

	set_name("cod");
	set_race("fish");
	set_alias("fish");
	set_short("cod");
	set_long("A small sea cod.\n");
	set_level(7);
	set_wc(9);
	set_hp(100);
	set_aggressive(0);
	set_whimpy(10);
	set_has_gills();
}
