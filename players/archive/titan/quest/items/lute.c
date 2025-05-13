	inherit "obj/weapon";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("lute");
	set_type(2);
	set_value(100);
	set_class(9);
	set_weight(1);
	set_short("a lute");
	set_long("Beautiful minstrel's lute.\n");
}
	init() {
	::init();
	add_action("hraj","play");
}
	hraj(str) {
	if(str=="on lute") {
	write("You are playing on lute.\n");
	say(this_player()->query_name()+" plays on lute.\n");
	return 1;
}
	else {
	notify_fail("Play on what ?\n");
	return 0;
}}
