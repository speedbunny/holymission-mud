	inherit "room/room";
	int n;

	reset(arg) {
	if(!present("guard",this_object())) {
	(n=0);
	{
	while(n<8) {
	move_object(clone_object("players/titan/quest/monsters/guard"),this_object());
	(n=n+1);
}}}
	if(!present("king",this_object())) {
	move_object(clone_object("players/titan/quest/monsters/king"),this_object());
}
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "Throne room";
	long_desc = "Tiez throne room.\n";
	
	dest_dir = ({"players/titan/quest/rooms/court","east",
	"players/titan/quest/rooms/library","south"
});

	property = ({"no_steal","no_sneak","no_teleport"});
}
