inherit "room/room";

reset(arg) {

    set_light(1);
    short_desc="A path in Mythwood";
    long_desc="You are walking along a path in Mythwood.\n";
    dest_dir=({
               "players/kelly/rooms/mythwood/mythpath3","north",
               "players/kelly/rooms/vill/woodroad","south",
             });
    ::reset();
    replace_program("room/room");
}


