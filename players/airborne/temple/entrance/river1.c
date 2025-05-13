inherit "room/room";

reset(arg){
  set_light(1);
  dest_dir = ({"players/airborne/temple/entrance/river2", "downstream",
	"players/airborne/temple/entrance/land5", "out", });
  short_desc = "River";
  long_desc = "The river begins here. The water flows down from some rocks\n"
	"to the north. Who knows what might lurk in these waters!?\n";
  items = ({"rocks", "The water is flowing steadily from these rocks",
	"water", "The water is clear and cold", });
  
replace_program("room/room");
}
