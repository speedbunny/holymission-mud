inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="A large open plain";

    long_desc="A large open plain. There is a big tree to the west.\n";

    dest_dir=({
               "room/plane5", "south",
               "room/plane10", "north",
               "room/plane3", "east",
               "room/big_tree", "west",
             });

    ::reset(arg);
    replace_program("room/room");
}

