inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "2halld";
  long_desc = 
	"You have reached the end of the hallway.\n"
        "To the north is a stairwell.\n"
        "It is kind of chilly in here.\n";
   dest_dir = ({"players/jake/upstairs2", "north",
        "players/jake/room7","west",
        "players/jake/room8","east",
        "players/jake/2hallc", "south" });

replace_program("room/room");
}


