inherit "room/room";


reset(arg) {

    set_light(1);
    short_desc="A path in Mythwood";
    long_desc="You are walking on a path in Mythwood.\n"+
              "To the north the wood lighten into a clearing.\n";
    dest_dir=({
               "players/kelly/rooms/mythwood/mythpath","south",
               "players/kelly/rooms/mythwood/clear1","north",
             });
    ::reset();
    replace_program("room/room");
}

