inherit "room/room";

reset(arg){
	set_light(1);
	dest_dir = ({"players/airborne/temple/entrance/bridge3", "north",
		"players/airborne/temple/entrance/bridge1", "south",
		"players/airborne/temple/entrance/river6", "down", });
	short_desc = "Rope bridge";
long_desc = "You are standing on a rope bridge. To the north you see land\n"+
	"and below you is the river. To the south is the begining of the\n"+
	"island. The temple shines in the distance and a tent is ahead to\n"+
	"the northeast.\n";

	items = ({"bridge", "A rope bridge",
		"temple", "The golden temple is still off in the distance",
		"land", "Green filled land",
		"river", "The water is flowing swiftly. It looks refreshing",
		"tent", "A large tent... looks a lot like a closed pavillion",});

  replace_program("room/room");

	}
