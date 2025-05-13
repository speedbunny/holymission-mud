

inherit "room/room";

reset(arg) {
    if (!present("sign"))
        move_object(clone_object("players/silas/obj/sign2"), this_object());
    if (arg) return;

    set_light(1);
    short_desc = "Maze Passage";
    no_castle_flag = 0;
    long_desc = 
        "You have arrived at the end of the passage. A large archway looms over you and\n"
        + "a magical field prevents you from seeing beyond the entrance. Streaks of blood\n"
        + "paint the walls surrounding the archway and you feel wary about entering \n"
        + "whatever lies beyond it. A large sign hangs on one of the walls.\n";
    items = ({
         "blood","Dark red blood stains",
         "archway","Ancient runes are etched into the archway",
         "sign","An old, rusty sign",
         "runes","They are illegible to you",
         "field","A vibrant green field, humming with energy",
            });
    dest_dir = 
        ({
        "/players/silas/caves/mpass1", "east",
        "/players/silas/maze/maze1", "west",
        });
    smell = "The moldy smell of the cave mixes with a foul stench coming from the maze.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
