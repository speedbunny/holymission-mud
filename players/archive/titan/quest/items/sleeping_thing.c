	inherit "obj/treasure";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_id("sleeping_thing");
	set_weight(0);
	set_long("Je tu.\n");
}
