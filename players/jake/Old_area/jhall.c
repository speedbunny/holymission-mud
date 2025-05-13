inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "jhall";
  long_desc = 
        "You are still walking down the hallway.\n"
        "It is somewhat dark in here\n"
        "You see some movement to the north.\n";
  dest_dir = ({ "players/jake/hall.c", "south",
        "players/jake/floor5","east",
        "players/jake/halla.c","north",
        "players/jake/floor4","west" });

replace_program("room/room");
}


