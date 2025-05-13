inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "floor1";
  long_desc = 
        "This is a student housing room.\n"
        "It is kind of messy (typical of a student)\n"
        "There is a ratty carpet on the floor.\n";
  dest_dir =  ({ "players/jake/hallk.c", "west" });

replace_program("room/room");
}

