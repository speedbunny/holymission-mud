inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Deep forest";

    long_desc="You are in the deep forest.\n";

    dest_dir=({
               "room/forest8", "west",
               "room/forest4", "east",
             });

    ::reset(arg);
    replace_program("room/room");
}
