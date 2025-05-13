inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "upstairs";
  long_desc = 
        "You are now on the second floor of Jake's place.\n"
        "You hear voices to the north.\n";
 dest_dir = ({ "players/jake/astair.c", "down",
        "players/jake/lounge2","north" });

replace_program("room/room");
}


