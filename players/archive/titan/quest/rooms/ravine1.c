	inherit "room/room";


	reset (arg) {

	set_light(1);
	short_desc = "In deep ravine";
	long_desc = 
	"You have entered into a narrow ravine. Around you are high mountains. To the\n"
        + "southeast ravine continue. To the northwest you can reenter the forest.\n"
	+ "There is small sign here.\n";

	dest_dir = ({ "players/titan/quest/rooms/ravine2","southeast",
		      "players/titan/quest/rooms/forest","northwest"});

	items = ({ "mountains","You see dark high mountains",
		"ravine","You stay on the bottom of deep ravine",
                "sign","You see golden sign near you"});
}
	init() {
	::init();
	add_action("get","get");
	add_action("climb","climb");
	add_action("read","read");
}
	get(str) {
	if(str=="sign") {
	write("This sign serve also other players, not only your.\n");
	return 1;
}}
	climb(str) {
	if(str=="mountain") {
	write("No way\n");
	return 1;
}}
       	read(str) {
	if(str=="sign") {
	write(" *** WELCOME TO KINGDOM OF HOGAN ***\n");
	return 1;
}}

