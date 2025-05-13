inherit "room/room";

reset(arg){
  set_light(1);
  dest_dir = ({"players/airborne/temple/levelc/room16", "south",
		"players/airborne/temple/levelc/room18", "east",
		"players/airborne/temple/levelc/room13", "west" });
  short_desc = "Passage break";
  long_desc = "The passage breaks off here. To the east you hear the cries of\n"
	"a mad-man. Be careful.\n";

replace_program("room/room");
}
