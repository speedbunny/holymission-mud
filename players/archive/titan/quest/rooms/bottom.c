	inherit "room/room";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "On foot of mount";
	long_desc =
		"You have entered in this strange place. Everywhere you look you see\n"
		+ "only the high peaks. In front of you sticks out a high peak. On the top\n"
		+ "leads steep path. Behind you is a dark ravine.\n"
;
	items = ({
		"path","Steep path leads to the top",
		"peak","High peak"
});
	smell = "You smell musty air";

	dest_dir = ({
		"players/titan/quest/rooms/ravine4","northwest",
		"players/titan/quest/rooms/middle","up",
});
}
