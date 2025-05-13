	inherit"room/room";

	reset(arg) {
	set_light(1);
	short_desc = "On the beach";
	long_desc =
	  "Beautiful small beach in the center of the high mountain.You are standing on\n"
	+ "yellow sand. You smell the salt in the air which arrives from the sea. There\n"
	+ "is breeze blowing through the air that makes you feel very peaceful.\n";

	smell = "You smell fresh air comming from sea. It is full of salt.";
	items = ({"sand","It looks like gold"});

	dest_dir =
	      ({"players/titan/quest/rooms/beach2","east",
		"players/titan/quest/rooms/beach3","south",
		"players/titan/quest/rooms/ravine2","northwest"});
}
