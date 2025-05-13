	inherit "room/room";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "On wall";
	long_desc = "Zatial on wall.\n";

	dest_dir = ({
		"players/titan/quest/rooms/tower31","west",
		"players/titan/quest/rooms/tower41","east"});

	property = ({"no_teleport","no_sneak","no_steal"});
}
