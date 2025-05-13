

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Cave Passage";
    no_castle_flag = 0;
    long_desc = 
        "You are walking along a small passage. Torches line the walls here and the\n"
        + "ground looks well-worn, as if someone had been walking here recently.\n";
    dest_dir = 
        ({
        "/players/silas/caves/pass4", "northwest",
        "/players/silas/caves/pass2", "southeast",
        });
    smell = "The smell of mold wafts around this cave.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
