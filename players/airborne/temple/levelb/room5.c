inherit "room/room";

reset(arg){
  set_light(0);
  dest_dir = ({"players/airborne/temple/levelb/room8", "north",
		"players/airborne/temple/levelb/stairs4", "south",
		"players/airborne/temple/levelb/room4", "east",
		"players/airborne/temple/levelb/room6", "west", });
  short_desc = "A fine room";
  long_desc = 
	"The room is a vast corridor with exits in all directions.\n";	
  clone_list = ({ 1, 1, "imp", "players/airborne/monsters/imp", 0 });

::reset();
replace_program("room/room");

}

