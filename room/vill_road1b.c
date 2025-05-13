inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Village road";

    long_desc=
              "A long road going east through the village. To the " +
              "south you notice "+
              "the entry to an old building.\n";

    dest_dir=({ "room/vill_road1","west",
                "room/vill_road2","east",
                "room/adv_guild","south",
             });

    ::reset(arg);
    replace_program("room/room");
}

