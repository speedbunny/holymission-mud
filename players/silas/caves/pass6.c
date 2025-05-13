

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Cave Passage";
    no_castle_flag = 0;
    long_desc = 
        "The small passageway continues towards a small room to the north and to a \n"
        + "large intersection to the south. Although the walls of this cave feel a bit\n"
        + "too confining for your tastes you don't feel claustrophobic.\n";
    dest_dir = 
        ({
        "/players/silas/caves/endpass", "north",
        "/players/silas/caves/pass5", "south",
        });
    smell = "The smell of mold wafts around this cave.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
