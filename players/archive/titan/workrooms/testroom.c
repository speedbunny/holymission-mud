	inherit"room/room";

	reset(arg) {
	set_light(1);
	short_desc ="Titan's testroom";
	
	long_desc = "This room is totaly empty. Wall contains by big boulder and floor is by very\n" +
		"strange material. There isnt windows and you see only one massive door.\n";
	dest_dir = ({
		"players/titan/workroom","west",
		"players/titan/quest/rooms/kobka","kobka"
});
	}
