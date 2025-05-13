inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="A large open plain";

    long_desc="A large bare open plain stretches out in all " +
              "directions from here. In all directions the view " +
              "seems the same, nothing breaks its monotony.\n";

    dest_dir=({ "room/plane11", "north",
        "room/plane8", "east",
        "room/plane3", "south",
        "room/plane10", "west" });

    ::reset(arg);
    replace_program("room/room");
}

