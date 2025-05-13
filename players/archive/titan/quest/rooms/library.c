	inherit "room/room";

	reset(arg) {
	if(!present("counsel",this_object())) {
	move_object(clone_object("players/titan/quest/monsters/counsel"),this_object());
}
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "Library";
	long_desc = 
		"This is a hogan library. Everywhere you look you see many shelves.\n"
		"There are many titles which counsil gather many years. In centre\n"
		"of the room are some comfortable armchairs. Close to armchairs is small\n"		
		"table. In corner is old desk full of books. Everywhere rules peace and\n"
		"stillness.\n";

	items = ({
		"armchairs","You see comfortable leather armchairs",
		"shelves","Shelves are full of books",
		"table","Small mahogany table",
		"desk","This desk use in reading books"});
                                      
	dest_dir = ({
		"players/titan/quest/rooms/throne","north"});

	property = ({"no_fight","no_steal","no_teleport"});
}
	init() {
	::init();
	add_action("sit","sit");
	add_action("zober","get");
}
	sit(str) {
	if(str=="at armchair") {
	write("You comfortable sit at armchair.\n");
	say(this_player()->query_name()+" sits at armhairs.\n");
	return 1;
}
	else {
	notify_fail("Sit where ?\n");
	return 0;
}}
	zober(str) {
	if(str=="book") {
	write("You cant get any book.\n");
	return 1;
}}
