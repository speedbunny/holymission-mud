	inherit "obj/treasure";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_id("horn of escape");
	set_alias("horn");
	set_short("A horn of escape");
	set_long("Small horn which helps you escape from everywhere.\n");
	set_value(1000);
	set_weight(1);
}
	init() {
	::init();
	add_action("trubit","blow");
}
	trubit(str) {
	if(str=="on horn"||str=="on horn of escape") {
	tell_room(environment(this_player()),"Suddenly came flying gigantic vulture and take "+this_player()->query_name()+" away ...\n");
	this_player()->move_player("\b\b\b\b\b\b\b fly away on the vulture.#players/titan/quest/rooms/medziroom");
	move_object(clone_object("players/titan/quest/items/nomotion"),this_player());
	return 1;
}
	else {
	notify_fail("blow on what ?\n");
	return 0;
}}
