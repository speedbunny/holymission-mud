inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "path5";
  long_desc = 
        "You are approaching Jake's place.\n"
        "It is directly north of you.\n";
  dest_dir = ({ "players/jake/enter.c", "north",
        "players/jake/path4.c","south" });

replace_program("room/room");
}

