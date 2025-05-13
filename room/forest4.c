inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Deep forest";

    long_desc="You are in the deep forest.\n";

    dest_dir=({
               "room/forest3", "north",
               "room/forest5", "west",
               "room/forest6", "east",
               "room/forest7", "south",
             });

    ::reset(arg);
    replace_program("room/room");
}
