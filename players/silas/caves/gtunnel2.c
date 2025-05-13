

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Narrow Tunnel";
    no_castle_flag = 0;
    long_desc = 
        "The tunnel widens here by a few feet, and it looks as if it opens into a large\n"
        + "cavern to the west. \n";
    dest_dir = 
        ({
        "/players/silas/caves/gtunnel1", "east",
        "/players/silas/caves/gledge", "west",
        });
    smell = "The mosses give off a vegetative smell.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
