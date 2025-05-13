inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "Long Tunnel";
    no_castle_flag = 0;
    long_desc = 
        "The tunnel continues through the depths of the mountain. To the north a faint\n"
        + "glimmer of light can be seen.\n";
    dest_dir = 
        ({
        "/players/silas/caves/caveexit", "north",
        "/players/silas/caves/tunnel5", "southeast",
        });
    smell = "A breeze of fresh air is coming from the north.\n";
    ::reset();
    replace_program("room/room");
}

