	inherit "room/room";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "On steep road";
	long_desc =
		  "You are standing somewhere on steep slope. Close to the path are some\n"
		+ "some boulders. You can see magnificent scenery from this part of the mountain\n"
		+ "range. The path leads further up to the top of the peak and down to the\n"
		+ "ravine.\n"
;
	smell = "You smell fresh air";
	items = ({
		"boulders","Big boulders covered with moss",
		"path","Mountain path",
		"top","You see outline some big building",
		"boulder","Big boulder covered with moss"});

	dest_dir = ({
		"players/titan/quest/rooms/bottom","down",
		"players/titan/quest/rooms/top","up"
});
}
