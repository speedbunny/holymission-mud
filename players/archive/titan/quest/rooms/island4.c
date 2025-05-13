	inherit "room/room";

#define CESTA "/players/titan/quest/rooms/"

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "On the cliff";
	long_desc = "Na ostrove.\n";

	dest_dir = ({
		CESTA+"island6","south",
		CESTA+"island5","southwest",
		CESTA+"island","west",
		CESTA+"island2","northwest",
		CESTA+"cave","north"});

	property = ({"no_steal","no_sneak","no_teleport"});
}
