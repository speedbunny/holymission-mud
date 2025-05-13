inherit "room/room";


reset(arg) {

    set_light(1);
    short_desc="A path in Mythwood";
    long_desc="You are walking on a path in Mythwood.\n";
    dest_dir=({
               "players/kelly/rooms/mythwood/mythpath","east",
               "players/kelly/rooms/mythwood/mythpath5","west",
             });

    clone_list = ({ 1, 1, "orc", "obj/monster",
                       ({ "set_name", "orc",
                          "set_alias", "orc",
                          "set_race", "orc",
                          "set_level", 5,
                          "set_hp", 150,
                          "set_short", "Foul Orc",
                          "set_long", "An orc of the infamous Mythwood variety",
                          "set_al", -50,
                          "set_aggressive", 1,
                          "set_size", 3,
                          "add_money", 30,
                          "set_ac", 4,
                          "set_wc", 12 }),
                   -1, 1, "knife", "obj/weapon",
                       ({ "set_name", "knife",
                          "set_short", "A knife",
                          "set_long", "A simple stone knife",
                          "set_wc", 7,
                          "set_weight", 1,
                          "set_value", 7}),
                  });
    ::reset();
    replace_program("room/room");

}


