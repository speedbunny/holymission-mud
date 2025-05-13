	inherit "room/room";

	reset(arg) {
	if(!present("ama",this_object())) {
	move_object(clone_object("players/titan/quest/monsters/ama"),this_object());
}
	::reset(arg);
	if(arg) return;
	set_light(1);
	short_desc = "Inside hut";
	long_desc =
		"This is small room inside of the small hut. It's furniture is simple. There\n"
		+ "are some chairs and comfortable bed by the wall. You didnt think that in this\n"
		+ "old hut is so bed. In center of this snug little room is black wooden table.\n"
	+ "This room had only one window which is very dirty. It's crazy because all is\n"
	+ "in order exept the window. In the corner is an open chest with strange tools\n"
	+ "in it and on the floor there are nets. The room gives you a rather snug\n"
	+ "impression.\n";

	items = ({"bed","Beautifull bed with pink quilt and pillow",
		"chest","It is full of strange tools",
		"window","Dirty window",
		"chair","Old wooden chair with carving",
		"table","Usual table",
		"floor","Wooden floor with slides parquets",
		"wall","Wall consist by big boulder"});
	dest_dir = ({"players/titan/quest/rooms/beach2","out"});
}
