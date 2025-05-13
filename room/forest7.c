inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Deep forest";

    long_desc = "You are in a deep forest. There is a small " +
                "path leading through the bushes to the south.\n";

    dest_dir=({
                "room/forest4", "north",
                "room/forest10", "west",

             });
    ::reset(arg);
    replace_program("room/room");
}
