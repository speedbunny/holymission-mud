	inherit "obj/treasure";

object ne;
	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_id("needle");
	set_alias("silver needle");
	set_short("A silver needle");
	set_long("Small but bristly instrument of old maid. Important thing for creating necklace.\n");
	set_weight(1);
	set_value(50);
}
 drop() {
	if(this_player()->command()=="give needle to dummy") {
 move_object("players/titan/quest/items/needle","players/titan/workrooms/dummy");
	destruct(this_object());
	return 0;
}
	else
	write("Silver needle disappears in small flame.\n");
	destruct(this_object());
	return 1;
}
