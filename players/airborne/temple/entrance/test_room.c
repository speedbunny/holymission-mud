inherit "room/room";
reset(arg){
  set_light(1);
  dest_dir = ({"players/airborne/temple/entrance/land4", "north",
	"players/airborne/temple/entrance/bridge3", "east", });
   short_desc = "Temple path";
   long_desc = "The small path you are on stretches north to the temple.\n";

   items = ({"path", "The path is nothing more than dirt",
	"temple", "The anceint temple. Looks rather impressive", });
   replace_program("room/room");
}
