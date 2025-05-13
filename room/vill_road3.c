inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Village road";

    long_desc=
              "A long road going east through the village. The " +
              "road leads out of the town towards the shore to the east.\n";

    dest_dir=({ "room/vill_shore","west",
                "room/jetty","east" });

    ::reset(arg);
    replace_program("room/room");
}

