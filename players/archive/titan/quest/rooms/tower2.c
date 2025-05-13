	inherit "room/room";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "Base of the northeastern tower";
	long_desc =
		"Hmm. You have appeared in base of the northeastern tower. There are\n"
		"nothing which fascinated your attention. From here leads steep staircase\n"
		"to the up and and passage leads back to the guard's room.\n";
	items = ({
		"staircase","Wooden steep staircase"
});

	dest_dir = ({
		"players/titan/quest/rooms/guards","west",
		"players/titan/quest/rooms/tower21","up"});

	property = ({"no_teleport","no_sneak","no_steal"});
}
