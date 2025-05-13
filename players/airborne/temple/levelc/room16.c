inherit "room/room";

reset(arg){
  set_light(1);
  dest_dir = ({ "players/airborne/temple/levelc/room17", "north",
		"players/airborne/temple/levelc/room11", "south" });
  short_desc = "Dark passage";
  long_desc = "This is a dark passage. It continues to the north and south\n";

replace_program("room/room");
}
