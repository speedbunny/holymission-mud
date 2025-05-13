inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Village Road";
    no_castle_flag = 0;
    long_desc = 
        "The road continues through the village of Keidall. To the north you see a \n"
        + "building which appears to be a shop while a sign reading KEIDALL SECURITIES\n"
        + "points at a shack which lies south of the road. \n";
    dest_dir = 
        ({
        "/players/silas/fghant/ks", "north",
        "/players/silas/fghant/kempty", "south",
        "/players/silas/fghant/keidall3", "east",
        "/players/silas/fghant/keidall5", "west",
        });
    smell = "Smoke and cow manure give off a pungent odor.\n";
}

query_light() {
    return 1;
}
