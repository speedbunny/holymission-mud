inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "upstairs2";
  long_desc = 
        "You have reached the second floor.\n"
        "The stairs proceed further up, or you can enter the hall "
	"to the south.\n";
  dest_dir = ({ "players/jake/stairj","down",
      	"players/jake/2halld","south",
	"players/jake/3stairs", "up" });

replace_program("room/room");
}


