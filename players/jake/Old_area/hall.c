inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "hall";
  long_desc = 
        "This is the hall north of the lounge.\n"
        "It continues north.\n";
  dest_dir = ({ "players/jake/jhall.c", "north",
        "players/jake/eastroom.c", "south",
        "players/jake/floor6","west",
        "players/jake/floor7","east" });

replace_program("room/room");
}

