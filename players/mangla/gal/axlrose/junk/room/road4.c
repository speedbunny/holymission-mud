inherit "room/room";

reset(arg){
    set_light(1);
    short_desc = "road";
    long_desc = "A dirt road\n";
    dest_dir=({
      "/players/axlrose/junk/room/road3", "west",
      "/players/axlrose/junk/room/road6", "southeast",
    });
    ::reset();
    replace_program("room/room");
}
