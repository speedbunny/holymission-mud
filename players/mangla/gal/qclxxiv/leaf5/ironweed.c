inherit "obj/treasure";
reset(arg) {
	if(arg) return;
    set_short("Ironweed");
    set_long("Qiberian Ironweed. A tough little plant with dull green little leafs.\n");
	set_id("herbs");
	set_alias("ironweed");
  	set_value(0);
  	set_weight(0);
}
init() {
	::init();
	add_action("eat","eat");
}
eat(str) {
	object soul;
	if (!id(str))  return; 
	write("You shiver from the very bitter taste.\n");
	soul = clone_object("players/qclxxiv/leaf5/hsoul");
	move_object(soul, this_player());
	destruct(this_object());
	return 1;
}

