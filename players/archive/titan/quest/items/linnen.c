	inherit "obj/treasure";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_id("piece of linnen");
	set_alias("linnen");
	set_short("A piece of linnen");
	set_long("Piece of white linnen. Maybe you can wave with it somewhere.\n");
	set_value(5);
}
	drop() {
	write("Linnen flow by wind.\n");
	destruct(this_object());
	return 1;
}
