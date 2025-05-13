	inherit "room/room";

#define CESTA "/players/titan/quest/rooms/"

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "In the cave";
	long_desc = "V jaskyni.\n";

	dest_dir = ({
		CESTA+"island4","south",
		CESTA+"island","southwest",
		CESTA+"island2","west",
		CESTA+"peak","up"});

	property = ({"no_steal","no_sneak","no_teleport"});
}
