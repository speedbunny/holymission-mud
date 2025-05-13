

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Pool Shore";
    no_castle_flag = 0;
    long_desc = 
        "This is rocky beach deep inside the mountain. Small waves lap up against the\n"
        + "shore and the distant sound of rushing water can be heard. You can enter the\n"
        + "pool by heading east or walk along a small passage into the mountain by\n"
        + "going west.\n";
    dest_dir = 
        ({
        "/players/silas/caves/pool2", "east",
        "/players/silas/caves/pass1", "west",
        });
    smell = "The air is damp and musty here.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
