

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Hall of Wizards";
    no_castle_flag = 0;
    long_desc = 
        "Although this part of the hall looks newer than its northern counterpart it\n"
        + "is no less dazzling. Sparkling tiles and the soft glow from the phosphorescent\n"
        + "mosses on the ceiling of the cave create an atmosphere that you will not soon\n"
        + "forget.\n";
    dest_dir = 
        ({
        "/players/silas/caves/hall1", "north",
        "/players/silas/caves/hall3a", "south",
        "/players/silas/caves/rasta", "east",
        "/players/silas/caves/silas", "west",
        });
}

query_light() {
    return 1;
}
