inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "westbase";
  long_desc = 
        "You have entered a dark and dismal room.\n"
        "Seems that someone, or something, has been in here too.\n";
  dest_dir = ({ "players/jake/basej.c","east",
        "players/jake/hole.c","hole" });

replace_program("room/room");
}


