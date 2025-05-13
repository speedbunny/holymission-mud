inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "room3";
  long_desc = 
        "This is a very peaceful looking room.\n"
        "In the corner is a desk, and a dresser is against the north wall.\n";
  dest_dir = ({ "players/jake/2halla", "west" });

replace_program("room/room");
}


