

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Village Intersection";
    no_castle_flag = 0;
    long_desc = 
        "A small path from the inside of the mountain intersects here with the main\n"
        + "village road which leads towards the center of the village of Keidall to the\n"
        + "west and Ragbutho forest to the east.\n";
    dest_dir = 
        ({
        "/players/silas/fghant/ragbut1", "east",
        "/players/silas/fghant/keidall2", "west",
        "/players/silas/fghant/base", "south",
        });
    smell = "A potpourri of nature's smells enters your nose.\n";
}


