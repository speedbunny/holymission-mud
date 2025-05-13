inherit "room/room";

reset(arg){
  set_light(1);
  dest_dir = ({"players/airborne/temple/entrance/land4", "down",
	"players/airborne/temple/levela/stairs2", "up", });
  short_desc = "Temple stairs";
  long_desc = "This is a stairway to the top of the temple. The stairs are\n"
	"the same golden color as the rest of the temple.\n";
  items = ({"temple", "Getting this close to the temple inspires awe!\n"
	"The temple is a bright golden color and looks as well as the day\n"
	"it was made. It does not show it's age at all", });

replace_program("room/room");
}

