inherit "room/room";

reset(arg){
    set_light(1);
    short_desc = "field";
    long_desc = "A battlefield.\n";
    dest_dir=({
      "/players/axlrose/junk/room/road3", "north",
      "/players/axlrose/junk/room/field14", "east",
      "/players/axlrose/junk/room/field16", "south",
    });
    ::reset();
    replace_program("room/room");
}
