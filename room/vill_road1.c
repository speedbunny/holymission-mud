inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Village road";

    long_desc=
              "A long road going east through the village. " +
              "The road narrows to a "+
              "track to the west. There is an alley to the " +
              "north and the south.\n";

    dest_dir=({
               "room/vill_track","west",
               "room/yard","north",
               "room/narr_alley","south",
               "room/vill_road1b","east",
             });

    ::reset(arg);
    replace_program("room/room");
}

