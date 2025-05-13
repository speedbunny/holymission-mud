	inherit "room/room";

#define CESTA "/players/titan/quest/rooms/"

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "On the centre of island";
	long_desc = "Na ostrove.\n";

	dest_dir = ({
		CESTA+"island5","south",
		CESTA+"island3","west",
		CESTA+"island1","northwest",
		CESTA+"island2","north",
		CESTA+"cave","northeast",
		CESTA+"island4","east",
		CESTA+"island6","southeast"});

	property = ({"no_steal","no_sneak","no_teleport"});
}
