inherit "room/room";

reset(arg){

	set_light(1);
	dest_dir = ({"players/airborne/temple/entrance/bridge2", "north",
		"players/airborne/temple/entrance/bridge1", "south", });
   replace_program("room/room");

	short_desc = "Rope bridge";
