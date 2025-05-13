

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Small Tunnel";
    no_castle_flag = 0;
    long_desc = 
        "The bluish glow is brighter here, and it illuminates this part of the tunnel.\n"
        + "You think that you can see four figures moving up ahead to the east, but maybe\n"
        + "it's just your imagination.\n";
    dest_dir = 
        ({
        "/players/silas/caves/stunnel3", "east",
        "/players/silas/caves/stunnel", "west",
        });
    smell = "You smell a damp and musty odor.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
