	inherit "room/room";

#define CESTA "/players/titan/quest/rooms/"

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "On the peak";
	long_desc = "V jaskyni.\n";

	dest_dir = ({
		CESTA+"cave","down"});

	property = ({"no_steal","no_sneak","no_teleport"});
}
