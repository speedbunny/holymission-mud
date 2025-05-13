	inherit"room/room";

	reset(arg) {

	set_light(1);
	short_desc = "You stand in shallow sea";
	long_desc = 
		"You have entered into the sea. In front of you spreads a beautifull gulf.\n"
		"In the heart of the gulf is a small island. Behind you is the beach and high\n" 
                "mountain range. You see no craft to take you to the island. Maybe you can\n"
		"dive and try to swim there.\n";

	items =
	      ({"sand","It looks like gold",
		"water","It is as crystal and pleasant warm",
		"sea","Straight blue sea. In distance you see island",
		"island","You see only small island in centre of gulf"});
	
	dest_dir =
	      ({"players/titan/quest/rooms/beach3","beach",
		"players/titan/quest/rooms/sea2","sea"});
}
	init () {
	::init();
        while(present("torch",this_player())) {
	object fakla,mokra;
	fakla=present("torch",this_player());
	destruct(fakla);
	mokra=clone_object("players/titan/quest/items/wet_torch");
	transfer(mokra,this_player());
}
	add_action("dive","dive");
}
	dive(str) {
	object mokra,fakla;
	if(str=="down"||str=="sea"||!str||str=="into the sea"||str=="into sea") {
	write("You are drowning into the sea.\n");
	say(this_player()->query_name()+" disappears under sea surface.\n");
	this_player()->move_player("into the sea#players/titan/quest/rooms/more7");
	return 1;
}
	else {
	notify_fail("Dive where ?\n");
	return 0;
}}

