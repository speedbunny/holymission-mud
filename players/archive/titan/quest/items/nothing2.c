	inherit "obj/treasure";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_id("nicik");
	set_weight(0);
	set_long("Nicik picik do pice.\n");
}
