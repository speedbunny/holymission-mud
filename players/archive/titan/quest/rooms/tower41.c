	inherit "room/room";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "Southeastern tower";
	long_desc =
		  "You are inside northwestern tower. This room is totaly empty. Except on the\n"
		+ "one wall you see a small loophole. Steep wooden staircase leads up and\n"
		+ "down.\n";

	items = ({
		"loophole","Usual loophole",
		"staircase","Wooden staircase"});

	dest_dir = ({
		"players/titan/quest/rooms/wall4","west",
		"players/titan/quest/rooms/wall3","north",
		"players/titan/quest/rooms/tower4","down",
		"players/titan/quest/rooms/tower42","up"});

	property = ({"no_teleport","no_sneak","no_steal"});
}
	init() {
	::init();
	add_action("pozri","look");
}
	pozri(str) {
	if(str=="through loophole"||str=="across loophole") {
	write("You are looking through loophole and you see nothing special.\n");
	return 1;
}}
