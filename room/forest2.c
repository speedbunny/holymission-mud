inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="In a forest";

    long_desc="You are in a big forest.\n";

    dest_dir=({
               "room/clearing", "east",
               "room/forest9", "west",
              });

    clone_list = ({ 1, 1, "troll", "obj/monster",
                           ({ "set_name", "troll",
                              "set_size", 4,
                              "set_level", 7,
                              "set_hp", 100,
                              "set_wc", 12,
                              "set_al", -12,
                              "set_short", "A troll",
                              "set_long", "It is a nasty troll that " +
                                          "look very aggressive.\n",
                              "set_race", "troll",
                              "set_spell_mess1", "The troll says: Mumble",
                              "set_spell_mess2", "The troll says: Your " +
                                                 "mother was a bitch!",
                              "set_chance", 20,
                              "set_money", 500,
                            }),
                 });

    ::reset(arg);
    replace_program("room/room");
}
