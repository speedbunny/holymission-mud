	inherit "obj/treasure";

	reset(arg) {
	::reset(arg);
	if(!arg) {

	set_id("kill_thing");
	set_weight(0);
	set_long("Kill_thing is here.\n");
}}

