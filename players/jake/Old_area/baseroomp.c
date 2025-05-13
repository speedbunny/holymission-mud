inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "baseroomp";
  long_desc = 
        "This is an empty storage room.\n"
        "Nothing is in here. [yet]\n";
  dest_dir =  ({ "players/jake/basek.c", "west" });

replace_program("room/room");
}

