inherit "room/room";

reset(arg){

	set_light(1);
	short_desc = "Rope Bridge";
long_desc="You are standing on the rope bridge over the lake. Ahead is an\n"
	+"island in the center of the lake.\n";
	dest_dir = ({"players/airborne/temple/entrance/bridge5", "north",
	"players/moonchild/trollslayer/ground", "south", });
		/* Changed by Moonchild */

	items = ({"bridge", "A rope bridge",
		"temple", "A golden temple is off in the distance", });
   replace_program("room/room");
}
