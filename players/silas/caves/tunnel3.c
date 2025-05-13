

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "Long Tunnel";
    no_castle_flag = 0;
    long_desc = 
        "You are wandering down a tunnel with no end in sight.\n"
        + "A faint light is shining up ahead, and you can make out the rough outline of a\n"
        + "huge figure in the gleam.\n";
    dest_dir = 
        ({
        "/players/silas/caves/tunnel4", "north",
        "/players/silas/caves/tunnel2", "south",
        });
    smell = "You smell a damp and musty odor.\n";
       ::reset();
       replace_program("room/room");
}

