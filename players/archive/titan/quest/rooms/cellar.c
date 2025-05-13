	inherit "room/room";

	reset(arg) {
	::reset(arg) ;
	if(arg) return;

	set_light(0);
	short_desc = "Wine cellar";
	long_desc = 
		"This is dark wine cellar. This is where the cook stores all of his components\n"
		"which he need for cooking. By the wall are barrels with famous wine. There\n"
		"are also various kinds of food. On hooks hang pieces of meat and on \n"
		"the ground lie vegetables and fruits. In corner of the room is a cupboard.\n";
	items = ({
		"barrels","Old barrels lie by the wall"
		"flesh","Many pieces of the flesh hanging in hooks"
		"vegetables","Many kinds of vegetables"
		"fruit","Many kind of fruits"});

	dest_dir = ({
		"players/titan/quest/rooms/kitchen","up"});

	property = ({"no_teleport","no_sneak","no_steal"});
}
