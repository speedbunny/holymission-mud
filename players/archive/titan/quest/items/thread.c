	inherit "obj/treasure";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_id("thread");
	set_alias("golden thread");
	set_short("A golden thread");
	set_long("Long piece of golden thread. Important thing for creating necklace.\n");
	set_value(100);
}
	drop() {
	write("You see than thread tear up to small fragment.\n");
	destruct(this_object());
	return 1;
}
