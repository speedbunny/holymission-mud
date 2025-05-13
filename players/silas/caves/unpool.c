

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Under the pool";
    no_castle_flag = 0;
    long_desc = 
        "Cold water brushes by your face as you swim underneath the surface of the pool.\n"
        + "The green glow is blinding you, making it hard to trace the direction from \n"
        + "where it originates. However, you can see a small hole to the north and after\n"
        + "a short while you realize that the glow is coming from that direction.\n";
    items = ({
         "hole","It looks ominous, and you are hesitant to enter it"
            });
    dest_dir = 
        ({
        "/players/silas/caves/lair", "north",
        "/players/silas/caves/pool2a", "up",
        });
    smell = "You decide not to inhale the water.\n";
    ::reset();
    replace_program("room/room");
}

