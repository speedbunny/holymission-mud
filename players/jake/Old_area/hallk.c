inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "hallk";
  long_desc = 
        "This is yet another stretch of hallway.\n"
        "To the north is a stairwell, rooms are to the east and west.\n";
  dest_dir = ({ "players/jake/stairj", "north",
        "players/jake/floor2.c","west",
        "players/jake/floor1.c","east",
        "players/jake/halla.c", "south" });

replace_program("room/room");
}
