		inherit "obj/monster";

	reset(arg) {
		::reset(arg);
	if(!arg) {
	set_name("carp");
	set_alt_name("river carp");
	set_level(6);
	set_al(0);
	set_race("fish");
	set_has_gills();
	set_short("You see river carp");
	set_long("You see medium size carp which is swiming around you.\n");
}}
