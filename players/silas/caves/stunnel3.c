

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Small Tunnel";
    no_castle_flag = 0;
    long_desc = 
        "At this point the blue glow is almost blindingly bright. The figures which you\n"
        + "recognized further back are now solid forms at the end of the tunnel towards\n"
        + "the east. \n";
    dest_dir = 
        ({
        "/players/silas/caves/stunnel4", "east",
        "/players/silas/caves/stunnel2", "west",
        });
    smell = "An easterly breeze brings the smell of dog to the room.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
