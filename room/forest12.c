inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Deep forest";

    long_desc= "You are in the deep forest.\n";

    dest_dir=({
               "room/south/sforst1", "south",
              "players/meecham/tower/entrance", "west",
               "room/crop5", "east",
             });

    ::reset(arg);
    replace_program("room/room");
}
