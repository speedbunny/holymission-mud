inherit "room/room";

reset(arg){
  set_light(-1);
  dest_dir = ({"players/airborne/temple/levelc/room14", "south" });
  short_desc = "Quiet room";
  long_desc = "This is a fairly small room that looks like it was once a private\n"
	"study for some great mage.\n";
  clone_list = ({ 1, 1, "jafros", "players/airborne/monsters/jafros", 0 });

::reset();
replace_program("room/room");
}
