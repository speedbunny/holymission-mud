	inherit "obj/monster";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("princess Claudia");
	set_alias("girl");
	set_race("human");
	set_level(8);
	set_al(-1500);
	set_gender(2);
	set_short("Princess Claudia");
	set_long("princezna xy.\n");
}
