inherit "room/room";

reset(arg){
    set_light(1);
    short_desc = "field";
    long_desc = "A battlefield.\n";
    dest_dir=({
      "/players/axlrose/junk/room/field3", "north",
      "/players/axlrose/junk/room/field8", "east",
    });
    ::reset();
    replace_program("room/room");
}
