	inherit "room/room";
	int n;

	reset(arg) {
	if(!present("guard",this_object())) {
	(n=0);
	{
	while(n<5) {
	move_object(clone_object("players/titan/quest/monsters/guard"),this_object());
	(n=n+1);
}}}
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "Armoury";
	long_desc = "Armoury zatial.\n";

	dest_dir = ({
		"players/titan/quest/rooms/court","south",
		"players/titan/quest/rooms/kitchen","west",
		"players/titan/quest/rooms/tower2","east"});

	property = ({"no_teleport","no_steal","no_sneak"});
}
