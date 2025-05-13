inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "Mulabi's Tent";
  smell = "The smell is getting bad! Don't know if you can stand it any longer.";
  long_desc = "This is Mulabi's tent.\n"
	"There are bones scattered all about. The tent has an opening\n"
	"to the north and west.\n";
  dest_dir = ({"players/airborne/temple/entrance/land2", "north",
		"players/airborne/temple/entrance/bridge3", "west", });
  items = ({"bones", "The bones are enough to make you want to be sick",});

  clone_list = ({ 1, 1, "mulabi", 
		"players/airborne/monsters/mulabi", 0 });

 ::reset();
 replace_program("room/room");
}
