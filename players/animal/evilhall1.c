inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "Evilcat world";
    no_castle_flag = 0;
    long_desc ="Evil catworld\n"
        + "\n"
        + "    This short hall leads north into\n"
        + "    darkness. You smell a strong feline\n"
        + "    scent from the north. You also sense\n"
        + "    a strong presence of evil. You feel\n"
        + "    as though you are being watched.\n"
        + "\n";
    dest_dir = 
        ({
        "/players/animal/evil9", "north",
        "/players/animal/enterhall", "south",
        });
}
 
query_long() {
    return long_desc;
}
query_light() {
    return 1;
}
