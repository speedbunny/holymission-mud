inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Village shore";

    long_desc=
              "The village shore path. This road runs from the " +
              "east back into the town to the west.\n";

    dest_dir=({
               "room/jetty","west",
               "room/vill_shore3","east",
             });

    ::reset(arg);
    replace_program("room/room");
}

