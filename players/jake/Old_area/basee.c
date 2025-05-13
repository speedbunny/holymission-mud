inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "asee";
  long_desc = 
        "You have reached the end of the basement hall.\n"
        "There is a solid brick wall south of you.\n"
        "There are rooms to the east and west.\n";
  items = ({ "wall", "A big brick wall" });
  dest_dir = ({ "players/jake/lintm.c","east",
        "players/jake/basek.c", "north",
        "players/jake/laundry", "west" });

replace_program("room/room");
}

