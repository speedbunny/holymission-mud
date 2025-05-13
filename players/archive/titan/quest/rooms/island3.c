	inherit "room/room";

#define CESTA "/players/titan/quest/rooms/"

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "On the cliff";
	long_desc = "Na ostrove.\n";

	dest_dir = ({
		CESTA+"island1","north",
		CESTA+"island2","northeast",
		CESTA+"island","east",
		CESTA+"island5","southeast"});

	property = ({"no_steal","no_sneak","no_teleport"});
}
