	inherit"room/room";

	reset(arg) {

	set_light(1);
	short_desc = "On the beach";
	long_desc =
	  "You stand on the border of the beach. This beach is in the heart of mountains\n"
	+ "and opens to a beautiful scenery. The sea is straight in front of you and\n"
	+ "you can see foam on top of waves. In weakly haze over sea you recognize some\n"
	+ "island. Whole beach is covered with yellow sand. To the southwest is\n"
	+ "narrow ravine. There is small shabby sign here.\n";
 
	smell = "You smell fresh air comming from sea. It is full of salt";
	items =
	      ({"sand","It looks like gold",
		"ravine","Narrow ravine which probably leads deeper into mountains",
		"window","Its dirty",
		"sea","Straight blue sea. In distance you see island",
		"island","You see only outline of some island in centre of gulf",
		"sign","You see wooden shabby sign"});
	
	dest_dir =
	      ({"players/titan/quest/rooms/beach1","north",
		"players/titan/quest/rooms/sea1","sea",
		"players/titan/quest/rooms/beach2","northeast",
		"players/titan/quest/rooms/ravine3","southwest"});
}
	init() {
	::init();
	add_action("read","read");
}
	read(str) {
	if(str=="sign") {
	write("Beware to rolling boulder. Enter only own risk.\n");
	return 1;
}
	else
return 0;
}

