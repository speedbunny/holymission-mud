	inherit "room/room";
	int i;

	reset(arg) {
	if(!present("captain",this_object())) {
	move_object(clone_object("/players/titan/quest/monsters/captain"),this_object());
}
	if(!present("guard",this_object())) {
	(i=0);
{
	while(i<3) {
	move_object(clone_object("players/titan/quest/monsters/guard"),this_object());
	(i=i+1);
}}}
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "Castle gate";
	long_desc =
		"Zatial iba gate.\n"
;

	dest_dir = ({
		"players/titan/quest/rooms/court","west"
});

	property = ({"no_sneak","no_teleport","no_steal"});
}
