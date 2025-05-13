

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Hall of Wizards";
    no_castle_flag = 0;
    long_desc = 
        "The hall continues with rooms to the east and west of here. You are surprised\n"
        + "at how clean this place is; the tiles reflect the light given off by the\n"
        + "phosphorescent mosses on the ceiling of the cave and the air here smells very\n"
        + "fresh.\n";
    dest_dir = 
        ({
        "/players/silas/caves/hall3", "north",
        "/players/silas/caves/hall1", "south",
        });
    smell = "Fresh, fragrant air revitalizes your senses.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
