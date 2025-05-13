	inherit "room/room";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "On wall";
	long_desc = "Zatial on wall.\n";

	dest_dir = ({
		"players/titan/quest/rooms/tower11","west",
		"players/titan/quest/rooms/tower21","east"});

	property = ({"no_teleport","no_sneak","no_steal"});
}
