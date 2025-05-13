

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Small Pool";
    no_castle_flag = 0;
    long_desc = 
        "You have ended up in a small pool in the land of F'ghant. In front of you you\n"
        + "can see a beautiful and very deep chasm. It seems as if stone has been hewn\n"
        + "out of the mountain in order to provide this view. The water from the stream\n"
        + "drops into the chasm, so it wouldn't be a bad idea if you climbed out before\n"
        + "you are swept away by another strong current.\n";
    dest_dir = 
        ({
        "/players/silas/fghant/square", "out",
        });
    smell = "The air here smells fresh and invigorating.\n";
}


