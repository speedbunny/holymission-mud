	inherit "room/room";


	reset (arg) {

	set_light(1);
	short_desc = "Crossroad";
	long_desc = 
		"Here the ravine is not as deep as other part of the mountains, but still\n"
		"very dangerous. The slopes are steep and at time you can hear the rattle\n"
		"of a landslide. From here you can go deeper into the mountain range to four\n"
		"directions.\n";

	dest_dir = ({
		"players/titan/quest/rooms/bottom","southeast",
		"players/titan/quest/rooms/quarry","west",
		      "players/titan/quest/rooms/ravine3","northeast",
		      "players/titan/quest/rooms/tarn","northwest"});

	items = ({ "mountains","You see dark high mountains",
		"ravine","You stay on the bottom of dangerous ravine",
		"slopes","Is very steep and nobody climb up here",
		"rocks","Loosen rocks",
		"peaks","Dark peaks rises up to sky"});
                
}
	init() {
	::init();
	add_action("climb","climb");
}
	climb(str) {
	if(str=="mountain") {
	write("No way.\n");
	return 1;
}}
