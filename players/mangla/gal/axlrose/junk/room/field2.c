inherit "room/room";

reset(arg){
    set_light(1);
    short_desc = "field";
    long_desc = "A battlefield.\n";
    dest_dir=({
      "/players/axlrose/junk/room/road1", "east",
      "/players/axlrose/junk/room/field6", "south",
      "/players/axlrose/junk/room/field1", "west",
    });
    ::reset();
    replace_program("room/room");
}
