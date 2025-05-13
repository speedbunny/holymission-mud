inherit "room/room";

reset(arg){
 set_light(-1);
 short_desc = "Stairwell";
 long_desc = 
   "This is the stairway deep in the ancient temple of the Old Ones. You are very deep so you had better take care. Who knows what evil might lurk this deep?\n";
 items = ({"stairs", "Golden stairs" });
 dest_dir = ({"players/airborne/temple/levelc/room12", "north", 
	"players/airborne/temple/levelc/room11", "east",
	"players/airborne/temple/levelb/stairs4", "up" });

replace_program("room/room");
}
