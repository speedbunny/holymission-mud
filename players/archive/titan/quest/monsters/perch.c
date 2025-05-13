	inherit "obj/monster";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("perch");
	set_race("fish");
	set_alias("perch");
	set_short("Big perch");
	set_long("Big perch swims near floor. It looks dangerous.\n");
	set_has_gills();
	set_level(16);
	set_hp(850);
	set_aggressive(0);
	set_whimpy(0);
}
