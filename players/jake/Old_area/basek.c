inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "basek";
  long_desc = 
        "It is very cold in here.\n"
        "You see a light to the west.\n";
  dest_dir =  ({ "players/jake/baseroomp.c","east",
        "players/jake/basea.c", "north",
        "players/jake/basee.c","south",
        "players/jake/samroom.c", "west" });

replace_program("room/room");
}

