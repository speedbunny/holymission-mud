inherit "room/room";

void reset(int arg) {

    set_light(1);
    short_desc="Village shore";
    long_desc=
              "The village shore path. This road runs from the " +
              "shore in the east back into the town to the west.\n";
    dest_dir=({
               "room/vill_shore2","west",
               "room/vill_shore4","east",
             });

    ::reset(arg);
    replace_program("room/room");
}

