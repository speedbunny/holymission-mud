inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    property = "no_teleport";
    short_desc = "Treasury";
    no_castle_flag = 0;
    long_desc = 
        "Heaps of gold and jewelry surround you as far as the eye can see. You won't be\n"
        + "able to carry all of it so you decide to settle for a small portion of the\n"
        + "loot.\n";
    dest_dir = 
        ({
        "/players/silas/maze/lair", "south",
        });
    smell = "The smell of rotten flesh wafts in from the south.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 0;
}
