inherit "room/room";

reset(arg){
    set_light(1);
    short_desc = "road";
    long_desc = "A dirt road\n";
    dest_dir=({
      "/players/axlrose/junk/room/road2", "north",
      "/players/axlrose/junk/room/road4", "east",
      "/players/axlrose/junk/room/field13", "south",
      "/players/axlrose/junk/room/road5", "southwest",
    });
    ::reset();
    replace_program("room/room");
}
