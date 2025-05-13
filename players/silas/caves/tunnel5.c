inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "Dark Room";
    no_castle_flag = 0;
    long_desc = 
        "The tunnel continues on with no end in sight from the northwest to the south.\n"
        + "You think that you can see a figure standing to the south, but you are unable\n"
        + "to make out any details.\n";
    dest_dir = 
        ({
        "/players/silas/caves/tunnel6", "northwest",
        "/players/silas/caves/tunnel4", "south",
        });
    smell = "You smell a damp and musty odor.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 0;
}
