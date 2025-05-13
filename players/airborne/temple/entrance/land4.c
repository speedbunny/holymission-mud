inherit "room/room";

reset(arg){
  set_light(1);
  dest_dir = ({"players/airborne/temple/entrance/stairs1", "north",
	"players/airborne/temple/entrance/land3", "south",
	"players/airborne/temple/entrance/land1", "east", });
  short_desc = "Temple path";
  long_desc = "The path to the temple continues to the north.\n"
	+"The lizardmen seem to be too aloof to guard this area well.\n";
  items = ({"path", "Dirt path to the temple",
	"temple", "The ancient golden temple shines before you. It towers above", });

  clone_list = ({ 1, 6, "lizardman", 
		"players/airborne/monsters/lizardman", 0,
		  2, 1, "lizardman", 
                "players/airborne/monsters/cook", 0});

 ::reset();
 replace_program("room/room");
 }
