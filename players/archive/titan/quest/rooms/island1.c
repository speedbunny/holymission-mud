	inherit "room/room";

#define CESTA "/players/titan/quest/rooms/"

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "On the cliff";
	long_desc = "Na ostrove.\n";

	dest_dir = ({
		CESTA+"island3","south",
		CESTA+"island2","east",
		CESTA+"island","southeast"});

	property = ({"no_steal","no_sneak","no_teleport"});
}
