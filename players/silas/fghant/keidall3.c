

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Village Road";
    no_castle_flag = 0;
    long_desc = 
        "As you approach the center of Keidall you notice that the number of passersby\n"
        + "has drastically increased. You can hear the clinging of glasses and roaring\n"
        + "laughter coming from the building to the north while you notice an almost\n"
        + "uninterrupted stream of well-dressed people shuffling in and out of the\n"
        + "southern building.\n";
    dest_dir = 
        ({
        "/players/silas/fghant/kbar", "north",
        "/players/silas/fghant/kestate", "south",
        "/players/silas/fghant/keidall2", "east",
        "/players/silas/fghant/keidall4", "west",
        });
    smell = "Smoke and cow manure give off a pungent odor.\n";
}

query_light() {
    return 1;
}
