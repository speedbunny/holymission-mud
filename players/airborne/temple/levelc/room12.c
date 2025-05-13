inherit "room/room";

reset(arg){
  set_light(-1);
  dest_dir = ({"players/airborne/temple/levelc/room13", "north",
		"players/airborne/temple/levelc/stairs5", "south", });
  short_desc = "Dark hallway";
  long_desc = "This is a dark hallway. The stairs are to the south and\n"
	"the hallway continues to the north. You are in very deep!\n"
	"Caution!\n";

replace_program("room/room");
}
