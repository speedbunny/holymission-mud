inherit "room/room";

reset(arg){
  set_light(0);
  dest_dir = ({"players/airborne/temple/levela/room2", "south",
	"players/airborne/temple/levela/room3", "west",
	"players/airborne/temple/levelb/stairs4", "down", });
  short_desc = "Stairwell";
  long_desc = "To the south and west there are dirty rooms.\n"
	"There is a staircase leading down, deeper into the temple of the Old Ones.\n";
  items = ({"staircase", "A golden colored staircase", });

replace_program("room/room");
}
