inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Deep forest";

    long_desc="You are in the deep forest.\n";

    dest_dir=({
               "room/forest9", "north",
               "room/forest4", "south",
             });

    ::reset(arg);
    replace_program("room/room");
}
