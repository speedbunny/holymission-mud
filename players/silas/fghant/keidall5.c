inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Village Road";
    no_castle_flag = 0;
    long_desc = 
        "You continue to stroll along the main thoroughfare in this small village. The\n"
        + "road leads further into Keidall to the east and heads to its outskirts to the\n"
        + "west. Two buildings of interest catch your eye; a majestic town hall\n"
        + "to the north and a small library to the south.\n";
    dest_dir = 
        ({
        "/players/silas/fghant/ktownhall", "north",
        "/players/silas/fghant/klibrary", "south",
        "/players/silas/fghant/keidall4", "east",
        "/players/silas/fghant/keidall6", "west",
        });
    smell = "Smoke and cow manure give off a pungent odor.\n";
}

query_light() {
    return 1;
}
