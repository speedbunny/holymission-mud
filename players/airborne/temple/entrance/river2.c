inherit "room/room";

reset (arg){
  set_light(1);
  dest_dir = ({"players/airborne/temple/entrance/river1", "upstream",
		"players/airborne/temple/entrance/river3", "downstream",
		"players/airborne/temple/entrance/land2", "out", });
  short_desc = "Bathing area";
  long_desc = "This is where the lizardmen flop around in their birthday suits.\n"
	"It is not a pretty site!\n";
  items = ({"water", "The water is slimey from all the lizardmen bathing here", });

  clone_list = ({ 1, 7, "lizardman",
		"players/airborne/monsters/nudelizard", 0 });

::reset();
replace_program("room/room");

}
