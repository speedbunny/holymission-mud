inherit "room/room";

reset(arg){

  set_light(1);
  dest_dir = ({"players/airborne/temple/entrance/bridge2", "north",
		"players/airborne/temple/entrance/bridge1", "south", });

   short_desc = "Rope bridge over island";
long_desc="The rope bridge carries you over the lake to an island in the\n"+
	"center. The land is below you at the start of the island and the\n"+
	"bridge continues north over a river in the island.\n";

   items = ({"lake", "The lake is calm and beautiful",
	"bridge", "Rope bridge",
	"land", "A sandy beach on the island",
	"rope bridge", "A simple rope bridge", });
  replace_program("room/room");
}
