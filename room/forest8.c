inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Deep forest";

    long_desc=
              "You are in the deep forest.\n" +
              "A path leads to the north, through the trees.\n";

    dest_dir=({
               "room/slope", "south",
               "room/forest5", "east",
               "/players/figleaf/smurf/path","north",
             });

    ::reset(arg);
    replace_program("room/room");
}
