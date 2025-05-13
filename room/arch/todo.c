inherit "/room/room";

void reset(int iArg) {
    if(!iArg) {
        set_light(1);

        short_desc = "Archwizards to-do discussion room";
        long_desc = "You are in the to-do discussion room of the \
Archwizards. Take a look at the board and participate in their \
wisdom...\n";

        dest_dir=({
            "/room/arch/general", "north",
        });

        property = ({
            "no_fight",
            "no_sneak",   
            "no_steal",   
            "no_teleport",
        });

        clone_list = ({
            1, 1, "board", "/boards/arch/todo", 0,
        });
    }
    ::reset(iArg);
}

void init() {
    if(!this_player()->query_archwiz() || !interactive(this_player())) {
        write("You feel dizzy and run towards the door to get some fresh \
air.\n");
        this_player()->move_player("quickly#/room/arch/general");
        return;
    }
    else
        ::init();
}
