inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Lair of the Giant";

    long_desc="There are mountains all around you.\n";

    dest_dir=({
               "room/giant_path", "east",
               "room/giant_conf", "west",
             });

    clone_list = ({ 1, 1, "giant", "obj/monster", 
                      ({    "set_name", "giant",
                            "set_level", 15,
                            "set_race", "giant",
                            "set_size", 4,
                            "set_short", "A giant",
                            "set_wc", 20,
                            "set_ac", 2,
                            "set_aggressive", 1, }),
                 });

    ::reset();
    replace_program("room/room");
}
