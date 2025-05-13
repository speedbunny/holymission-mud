inherit "room/room";

reset(arg){
    set_light(1);
    short_desc = "road";
    long_desc = "A dirt road\n";
    dest_dir=({
      "/players/axlrose/junk/room/field3", "east",
      "/players/axlrose/junk/room/road2", "south",
      "/players/axlrose/junk/room/field2", "west",
    });
    ::reset();
    replace_program("room/room");
}
