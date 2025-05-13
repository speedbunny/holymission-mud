	inherit "room/room";

	reset(arg) {
	if(!present("observer",this_object())) {
	move_object(clone_object("players/titan/quest/monsters/observer"),this_object());
}
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "Top of nortwestern tower";
	long_desc = 
		"You are on the top of nortwestern tower. You can see beautiful scenery far\n"
		+ "far bellow. Deep ravines, high peaks, small tarns and sea gulf. In the\n"
 		+ "center of the gulf you see a small island. It's the famous, but deadly, island\n"
 		+ "of BLUR. People say that on this island there lives a thing of great evil.\n";
	smell = "You smell fresh air";
	items = ({
		"tarns","Small mountain tarns",
		"peaks","High peaks with steep slopes",
		"gulf","Sea gulf",
		"island","Dangerous island of Blur. Around island are strange clouds",
		"tower","High tower"});

	dest_dir = ({
		"players/titan/quest/rooms/tower11","down"});

}
