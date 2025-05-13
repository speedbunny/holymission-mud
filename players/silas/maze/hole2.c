inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    property = "no_teleport";
    short_desc = "Hole";
    no_castle_flag = 0;
    long_desc = 
        "By now the growls have become louder and more menacing and you can feel the\n"
        + "foul breath of the creature penetrating your nasal passages. The monster must\n"
        + "be right below you now. Will you risk entering its lair?\n";
    dest_dir = 
        ({
        "/players/silas/maze/hole1", "up",
        "/players/silas/maze/lair", "down",
        });
    smell = "The stench from below is almost overpowering here.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 0;
}
