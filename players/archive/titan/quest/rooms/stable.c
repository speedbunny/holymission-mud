   	inherit "room/room";

	reset(arg) {
	if(!present("feeder",this_object())) {
	move_object(clone_object("players/titan/quest/monsters/servant"),this_object());
}
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "Stable";
	long_desc =
		  "This is famous Hogan's stable. There are only thoroughbred horses.\n"
		+ "Breeding horses is the king's hobby. Oo the walls are many torches\n"
		+ "which light up whole stable. Horses stay in there boxes. Between\n"
		+ "horse boxes is feeding passage which carries food to the horses.\n";
	dest_dir = ({
		"players/titan/quest/rooms/court","north",
		"players/titan/quest/rooms/tower4","east"});

	property = ({"no_teleport","no_steal","no_sneak","has_fire"});

	smell = "It smells horses here";
	items = ({
		"horses","You see only thoroughbred horses",
		"stable","Normal stable",
});
}
