

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Pool";
    no_castle_flag = 0;
    long_desc = 
        "As you swim along you notice a small current moving to the north. You can also\n"
        + "hear a faint rushing sound coming from that direction. If following the \n"
        + "current doesn't appeal to you you can swim to the west or the south.\n";
    dest_dir = 
        ({
        "/players/silas/caves/pool3", "north",
        "/players/silas/caves/pool1", "south",
        "/players/silas/caves/pool2b", "west",
        });
    smell = "The air here has a stuffy quality to it.\n";
    ::reset();
    replace_program("room/room");
}


