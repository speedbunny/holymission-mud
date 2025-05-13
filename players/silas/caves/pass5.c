

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Cave Intersection";
    no_castle_flag = 0;
    long_desc = 
        "You have reached an intersection of three passages. A large passage branches\n"
        + "away from the north/south path and heads towards a large jewel-encrusted\n"
        + "archway to the distant west.\n";
    dest_dir = 
        ({
        "/players/silas/caves/pass6", "north",
        "/players/silas/caves/pass4", "south",
        "/players/silas/caves/mpass1", "west",
        });
    smell = "The smell of mold wafts around this cave.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
