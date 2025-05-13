inherit "room/room";


reset(arg) {

    set_light(1);
    short_desc="A path in Mythwood";
    long_desc="You are walking on a path in Mythwood.\n";
    dest_dir=({
               "players/kelly/rooms/mythwood/mythpath","west",
//             "players/kelly/rooms/mythwood/mythpath6","east",
               "players/kelly/rooms/mythwood/mythpath8","south",
             });

    ::reset();
    replace_program("room/room");
}

