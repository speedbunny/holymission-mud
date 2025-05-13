inherit "room/room";

reset(arg){
  set_light(1);
  dest_dir = ({"players/airborne/temple/entrance/river6", "upstream", });
  short_desc = "River's end";
  long_desc = "The river crashes down on a bed of sharp rocks to the west.\n"
	"You would most certainally perish if you tried to follow.\n";
  items = ({"rocks", "The rocks catch the water as it falls below", });
  
replace_program("room/room");
}
