

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Pool";
    no_castle_flag = 0;
    long_desc = 
        "You are swimming in a natural pool in one of the many caverns hidden in the\n"
        + "mountain. The water is quite chilly and you move around to stay warm. A ledge\n"
        + "is towering above you, but there seems to be no way to reach it. You can swim\n"
        + "to the north or west in the search for an exit.\n";
    items = ({
         "ledge","It looks like the ledge you jumped off of"
         
             });
    dest_dir = 
        ({
        "/players/silas/caves/pool2", "north",
        "/players/silas/caves/pool2a", "west",
        });
    smell = "The air here has a stuffy quality to it.\n";
    ::reset();
    replace_program("room/room");
}


