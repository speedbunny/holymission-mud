	inherit "room/room";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "Base of the southeastern tower";
	long_desc =
		"You have entered to base of the southeastern tower. This room is not\n"
		"very interesting because there is only steep staircase leads to the\n"
		"up and passage leads to the stable.\n";
	items = ({
		"staircase","Wooden staircase leads to the higher parts of this tower"
});
	dest_dir = ({
		"players/titan/quest/rooms/stable","west",
		"players/titan/quest/rooms/tower41","up"});

	property = ({"no_teleport","no_sneak","no_steal"});
}
