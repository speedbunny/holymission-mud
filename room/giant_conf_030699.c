inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Giants conference of human bashing";

    long_desc="You are at the yearly conference of Human bashing, " +
              "organized by the giants. To the north, there is a " +
              "shop. It is just an ordinary shop. The mountains " +
              "to the west are impenatrable.\n";

    dest_dir=({"room/giant_lair","east",
               "/players/padrone/secret_police/shop","north",
             });

    clone_list = ({ 1, 1, "frostgiant", "obj/monster",
                     ({ "set_name", "giant",
                        "set_alias", "frostgiant",
                        "set_race", "giant",
                        "set_size", 4,
                        "set_level", 15,
                        "set_short", "A frost giant",
                        "set_wc", 20,
                        "set_ac", 2,
                        "set_al", -150,
                        "set_dex", 30,
                        "set_aggressive", 1, }),
                   -1, 1, "rapier", "obj/weapon",
                     ({ "set_name", "rapier",
                        "set_alias", "ice rapier",
                        "set_short", "An ice rapier",
                        "set_class", 16,
                        "set_weight", 2,
                        "set_value", 2000,
                        "set_type", 2, }),
                    2, 1, "stonegiant", "obj/monster",         
                     ({ "set_name", "giant", 
                        "set_alias", "stonegiant",
                        "set_race", "giant",
                        "set_size", 4,
                        "set_level", 15,
                        "set_short", "A stone giant",
                        "set_wc", 20,
                        "set_ac", 2,
                        "set_al", -150,
                        "set_str", 30,
                          "set_aggressive", 1, }),
                   -2, 1, "club", "players/cashimor/objects/club", 0, 
                    3, 1, "firegiant", "obj/monster", 
                     ({ "set_name", "giant",
                        "set_alias", "firegiant",
                        "set_level", 15,
                        "set_size", 4,
                        "set_race", "giant",
                        "set_short", "A fire giant",
                        "set_wc", 20,
                        "set_ac", 2,
                        "set_al", -150,
                        "set_dex", 25,
                        "set_str", 25,
                        "set_aggressive", 1, }),
                   -3, 1, "sword", "obj/weapon", 
                     ({ "set_name", "sword",
                        "set_alias", "sword of fire",
                        "set_short", "sword of fire",
                        "set_class", 17,
                        "set_weight", 4,
                        "set_value", 2000,
                        "set_type", 0, }),
                });        

    ::reset();
    replace_program("room/room");
}
