	inherit "room/room";

	reset(arg) {
	if(!present("nixie",this_object())) {
	
	move_object(clone_object("players/titan/quest/monsters/nixie"),this_object());
}
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "By the lake";
	long_desc = 
		"This is favourite area of nixie. There she spend all free time.\n";

	dest_dir = ({"players/titan/quest/rooms/clearing","south",
		"players/titan/quest/rooms/lake","lake"});
}


