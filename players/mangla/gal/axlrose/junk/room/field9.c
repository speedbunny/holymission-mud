inherit "room/room";

reset(arg){
    set_light(1);
    short_desc = "field";
    long_desc = "A battlefield.\n";
    dest_dir=({
      "/players/axlrose/junk/room/field5", "north",
      "/players/axlrose/junk/room/field10", "east",
      "/players/axlrose/junk/room/field12", "south",
    });
    ::reset();
    replace_program("room/room");
}
