	inherit "obj/treasure";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_id("wet torch");
	set_value(10);
	set_short("a wet torch");
	set_long("You see wet torch.\n");
}
	init() {
	::init();
	add_action("light","light");
}
	light(str) {
	if(str=="torch") {
	write("Sorry, this torch is wet.\n");
	return 1;
}}

