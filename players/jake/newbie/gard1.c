inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "gard1";
  long_desc = 
        "This is a grassy path through Jake's garden.\n"
        "You hear birds chirping, and he air is fresh.\n"
        "Beautiful flowers are to either side of you.\n";
  dest_dir =  ({ "players/jake/gard10", "east",
        "players/jake/gard2", "west" });

replace_program("room/room");
}

