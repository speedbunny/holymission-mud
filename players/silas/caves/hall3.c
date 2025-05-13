

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Hall of Wizards";
    no_castle_flag = 0;
    long_desc = 
        "You have arrived at the northern end of this lavish hall. Three rooms lie to\n"
        + "your north, east and west and the hall extends back to the south. A feeling\n"
        + "of great power surrounds you as you stand here; powerful magic must be in use\n"
        + "here.\n";
    dest_dir = 
        ({
        "/players/silas/caves/silas", "north",
        "/players/silas/caves/hall2", "south",
        "/players/silas/caves/mountain", "east",
        "/players/silas/caves/amazon", "west",
        });
    smell = "Fresh, fragrant air revitalizes your senses.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
