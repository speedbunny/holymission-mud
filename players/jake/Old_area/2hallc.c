inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "2hallc";
  long_desc = 
	"You are still travelling down the hallway.\n"
	"There is a flickering light making the hallway somewhat dim.\n";
  dest_dir = ({"players/jake/2halld","north",
        "players/jake/room5","west",
      	"players/jake/2halla","south" });

replace_program("room/room");
}


