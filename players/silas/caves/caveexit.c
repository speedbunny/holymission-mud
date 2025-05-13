inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Cave Exit";
    no_castle_flag = 0;
    long_desc = 
        "The tunnel ends here and the path leads north towards the lands of F'ghant. \n"
        + "You can also enter the huge mountain which looms above you to the south if you\n"
        + "so desire.\n";
    dest_dir = 
        ({
        "/players/silas/fghant/uppath", "north",
        "/players/silas/caves/tunnel6", "south",
        });
    smell = "A fresh breeze is blowing from the north.\n";
       ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
