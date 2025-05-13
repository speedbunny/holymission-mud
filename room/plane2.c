inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="A large open plain";

    long_desc="You are in a large bare open plain, extending as " +
              "far as the eye can see in all directions. A few " +
              "birds fly overhead - you can sometimes hear their " +
              "cries echoing off the castle that is also floating " +
              "there in the sky. Maybe you could jump to it.\n";

    dest_dir=({ "room/plane3", "north",
                "room/plane4", "east",
                "room/plane1", "south",
                "room/plane5", "west",
                "players/emerald/good/evil/enterhall", "jump",
             });

    items=({ "birds", "They look like vultures, searching for prey" });

    ::reset(arg);
    replace_program("room/room");
}

