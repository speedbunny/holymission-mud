inherit "room/room";

reset(arg){
  set_light(1);
  dest_dir = ({"players/airborne/temple/entrance/bridge2", "up",
	"players/airborne/temple/entrance/river5", "upstream",
	"players/airborne/temple/entrance/river7", "downstream", });
  short_desc = "River under the bridge";
  long_desc = "You are standing in a river. It is about 4 feet deep and the\n"
	+"water is flowing pretty fast. The flow downstream is to the west\n"
	+"and the flow upstream is to the east.\n";
  items = ({"bridge", "The rope bridge. Its a wonder it held you up", });
  
replace_program("room/room");
}
