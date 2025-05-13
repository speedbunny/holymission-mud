inherit "room/room";

reset(arg){
  set_light(-1);
  short_desc = "Bahkihr's room.";
  long_desc = "This room is mostly barren. Looks like someone had\n"
		"been using this room to rest.\n";
  dest_dir = ({"players/airborne/temple/levelc/room17", "west",
	       "players/airborne/temple/levelc/room19", "east" });
  clone_list = ({ 1, 1, "bahkihr", "players/airborne/monsters/bahkihr", 0,
		2, 1, "air", "players/airborne/monsters/air", 0,
		3, 1, "earth", "players/airborne/monsters/earth", 0 });

::reset();
replace_program("room/room");
}
