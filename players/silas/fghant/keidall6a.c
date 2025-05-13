

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Village Road";
    no_castle_flag = 0;
    long_desc = 
        "This is the western end of the village of Keidall. Towards the east you can see\n"
        + "many buildings lining the main street, and a path heads west into a large\n"
        + "valley.\n";
    dest_dir = 
        ({
        "/players/silas/fghant/keidall5", "east",
        "/players/silas/fghant/valley1", "west",
        });
}

query_light() {
    return 1;
}
