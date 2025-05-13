inherit "room/room";

reset(arg){
  set_light(1);
  dest_dir = ({"players/airborne/temple/entrance/river2", "upstream",
	"players/airborne/temple/entrance/river4", "downstream", });
  short_desc = "River";
  long_desc = "The river flows steady.\n";

replace_program("room/room");
}
