inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Guard Chamber";
    no_castle_flag = 0;
    long_desc = 
        "The tunnel ends here in a large chamber. A passage once led into the land of\n"
        + "F'ghant from here but ever since the great earthquake this exit has been\n"
        + "blocked. All that can be seen now in that direction is a large pile of\n"
        + "rubble. Guards are posted here to defend against the Sna'trach should they\n"
        + "decide to force their way through the rubble and continue their invasion.\n";
    dest_dir = 
        ({
        "/players/silas/caves/tunnel6", "south",
        });
    smell = "The musty smell of rocks and stones lingers here.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
