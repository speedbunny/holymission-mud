inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "3stairs";
  long_desc = 
        "You have reached the top of the stairs.\n";
  dest_dir = ({ "players/jake/upstairs2", "down",
        "players/jake/suite", "south" });

replace_program("room/room");
}


