inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(2);
  short_desc = "basea";
  long_desc = 
        "You have wandered further into the basement.\n"
        "It is fairly dark in here.\n"
        "You hear some humming sounds coming from the south.\n";
  dest_dir = ({ "players/jake/basej.c", "north",
        "players/jake/basek.c", "south",
        "players/jake/baseeast.c","east",
        "players/jake/baserooma.c", "west" });

replace_program("room/room");
}


