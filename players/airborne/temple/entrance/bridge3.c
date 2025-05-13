inherit "room/room";
reset(arg){
  set_light(1);
  dest_dir = ({"players/airborne/temple/entrance/land1", "north",
	"players/airborne/temple/entrance/bridge2", "south",
	"players/airborne/temple/entrance/tent", "east",
        "players/warlord/trans/port3","up",
	"players/airborne/temple/entrance/land3", "west", });
  short_desc = "Rope bridge";
  long_desc = "The bridge meets land here. You see an entrance to the tent to\n"
	+"the east. Foul smells and screams of pain burst from the tent.\n";
   smell = "You smell something very nasty comeing from the tent.";

	items = ({"bridge", "Rope bridge",
		"tent", "A large open tent. Seems that there is a lot of activity inside", });
  replace_program("room/room");
}
