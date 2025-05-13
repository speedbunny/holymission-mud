	inherit "room/room";


	reset (arg) {

	set_light(1);
	short_desc = "In ravine";
	long_desc = 
	  "You are in ravine. Everything around you is dark, because sun is blocked\n"  
        + "by the high peaks. To the southeast you see more light and ravine continues\n"
	+ "to the northwest.\n";

	dest_dir = ({ "players/titan/quest/rooms/ravine1.c","northwest",
		      "players/titan/quest/rooms/beach1.c","southeast"});

	items = ({"ravine","Dark ravine",
		"peaks","Their tops is in clouds"});
}

