inherit "room/room";

reset(arg){
  set_light(1);
  dest_dir = ({"players/airborne/temple/entrance/river4", "upstream",
	"players/airborne/temple/entrance/river6", "downstream", });
  short_desc = "River";
  long_desc = "The river flows to the east and west. You get the feeling\n"
	"something dangerous might be swimming nearby.\n"
	"To the west the river flows under the bridge.\n";
  items = ({"bridge", "Rope bridge", });
  
replace_program("room/room");
}
