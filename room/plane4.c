inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="A large open plain";

    long_desc="A large windswept open plain stretches out north " +
             "and west of here. To the east is a large pipe which leads into "+
              "the cliffside. Far above you can make out the walls of what "+
            "appears to be a prison. There are steps going up the eastside of the cliffs "+
            "however there is no way to climb south.\n";
              "ground becomes too rocky to continue.\n";

    dest_dir=({ "room/ruin", "north",
                "room/plane2", "west",
                "players/pretzel/area/rooms/entrance","east",
               "players/pretzel/area/rooms/hilltop","up",
             });

    ::reset(arg);
    replace_program("room/room");
}

