inherit "room/room";

reset(arg){
  set_light(1);
  dest_dir = ({"players/airborne/temple/entrance/land2", "south",
	"players/airborne/temple/entrance/river1", "jump", });
  short_desc = "Water's edge";
  long_desc= "The path leads to a river bank. The water looks dangerous but\n"
	+"the brave might 'jump' in.\n";

  items = ({"water", "The water looks dangerous",
	"river bank", "The river bank is holding the water back",
 	"path", "A well traveled dirt path", });

  smell = "Smell your pants!";
  replace_program("room/room");
}
