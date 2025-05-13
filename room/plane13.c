inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="A large open plain";

    long_desc="This is the northeastern end of a large open plain. " +
              "To the north and east you can see mountains, but " +
              "they are much too steep to climb.\n";

    dest_dir=({ "room/plane11", "west",
             });

    items=({ "mountain", "The mountains are much too steep to climb",
             "mountains", "The mountains are much too steep to climb",
          });

    ::reset(arg);
    replace_program("room/room");
}

