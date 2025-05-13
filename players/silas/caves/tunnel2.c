inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "Dark room";
    no_castle_flag = 0;
    long_desc = 
        "You are wandering down a long tunnel with no end in sight.\n";
    dest_dir = 
        ({
        "/players/silas/caves/tunnel3", "north",
        "/players/silas/caves/tunnel1", "south",
        "/players/silas/caves/stunnel", "east",
        });
    smell = "You smell a damp and musty odor.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 0;
}

