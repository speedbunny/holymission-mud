	inherit "room/room";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "Clearing";
	long_desc = 
		"Beautiful clearing.\n";

	dest_dir = ({"players/titan/quest/rooms/nixier","north"});
}
	init() {
	::init();
	add_action("spat","sleep");
}
	spat() {
	object sl_t;
	if(present("sleeping_thing",this_player())) {
	sl_t=present("sleeping_thing",this_player());
	destruct(sl_t);
	call_out("sleeping",5);
}
	else {
	write("You sleep sweetly.\n");
	return 1;
}}
	sleeping() {
	write("Nixie says: I bring you my horn of escape.\n");
	write("Nixie tells you: This horn rescue you from no escapingarea.\n");
	write("Nixie gives you horn.\n");
	write("Nixie leaves to nowhere.\n");
	move_object(clone_object("players/titan/quest/items/mirror"),this_player());
}
	


	

