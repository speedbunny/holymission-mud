

inherit "room/room";

reset(arg) {
    if (!present("hand"))
       move_object(clone_object("players/silas/obj/hand"), this_object());
    if (arg) return;

    set_light(1);
    short_desc = "Cave Passage";
    no_castle_flag = 0;
    long_desc = 
        "You are walking along a small passage. Torches line the walls here and the\n"
        + "ground looks well-worn, as if someone had been walking here recently.\n";
    dest_dir = 
        ({
        "/players/silas/caves/pass1", "east",
        "/players/silas/caves/pass3", "northwest",
        });
    smell = "The smell of mold wafts around this cave.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
