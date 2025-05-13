inherit "room/room";

reset(arg){
  set_light(1);
  dest_dir = ({"players/airborne/temple/entrance/land5", "north",
	"players/airborne/temple/entrance/tent", "south",
	"players/airborne/temple/entrance/river2", "bathe",
	"players/airborne/temple/entrance/land1", "west",});
  short_desc = "River bank";
  long_desc= "You are standing alongside the river. The Lizardmen use this\n"
    +"area to bathe. There is a large smelly tent to the south and the\n"
    +"river is to the east.\n";

  items = ({"river", "The lizardmen bathe there",
	"tent", "A large tent with an opening to the south",
	"river bank", "The river bank is holding the water back", });
  smell = "A very nasty smell is coming from the tent to the south.";

  clone_list = ({ 1, 1, "lizardman", 
		"players/airborne/monsters/nudelizard", 0});

  ::reset();
  replace_program("room/room");
}
