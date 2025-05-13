inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "Small Tunnel";
    no_castle_flag = 0;
    long_desc = 
        "This small tunnel winds away from the main passage and heads towards a strange\n"
        + "blue glow. Maybe you should continue east and investigate it.\n";
    dest_dir = 
        ({
        "/players/silas/caves/stunnel2", "east",
        "/players/silas/caves/tunnel2", "west",
        });
    smell = "You smell a damp and musty odor.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 0;
}
