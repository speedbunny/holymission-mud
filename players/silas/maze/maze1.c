inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    property = "no_teleport";
    short_desc = "Maze";
    no_castle_flag = 0;
    long_desc = 
        "This is the maze of Argannos; all passages look alike. You wonder if you will\n"
        + "ever find your way out of here.\n"
        + "A large archway marks the exit of the maze to the east.\n";
    dest_dir = 
        ({
        "/players/silas/maze/maze2", "north",
        "/players/silas/maze/maze3", "south",
        "/players/silas/caves/mpass2", "east",
        "/players/silas/maze/maze2", "west",
        });
    smell = "The faint smell of human flesh drifts through this maze.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
