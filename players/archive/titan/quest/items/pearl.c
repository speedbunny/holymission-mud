	inherit "/obj/treasure";

	reset (arg) {
	if (arg) return;

	set_id("pearl");
	set_alias("small pearl");
	set_short("A small pearl");
	set_long("You see beautifull small pearl. It plays all colors.\n");
	set_value(100);
	}
	drop() {
	write("Pearl breaks into tiny pieces.\n");
	destruct(this_object());
	return 1;
}
