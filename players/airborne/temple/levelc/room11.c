inherit "room/room";

reset (arg){
  set_light(0);
  short_desc = "Rest area";
  long_desc =
"This place looks like a comfortable place to rest. "
"At least it does to Kane the Troll!\n";
  dest_dir = ({"players/airborne/temple/levelc/room16", "north",
	"players/airborne/temple/levelc/stairs5", "west", });
  clone_list = ({ 1, 1, "kane", "players/airborne/monsters/kane", 0 });

::reset();
replace_program("room/room");
}
