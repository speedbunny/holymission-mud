inherit "room/room";

reset(arg){
  set_light(-1);
  dest_dir = ({"players/airborne/temple/levelc/room14", "north",
		"players/airborne/temple/levelc/room12", "south",
		"players/airborne/temple/levelc/room17", "east", });
  short_desc = "Passage break";
  long_desc = "There is a break in the passage here. To the east you can see\n"
     "a distant light. To the north the passage continues, as dark as it was before.\n";

replace_program("room/room");
}
