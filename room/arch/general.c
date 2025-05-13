inherit "/room/room";

void reset(int iArg) {
    if(!iArg) {
        set_light(1);

        short_desc = "Archwizards general discussion room";
        long_desc = "You are in the general discussion room of the \
Archwizards. Take a look at the board and participate in their \
wisdom...\n";

        dest_dir=({
            "/room/arch/todo", "south",
            "/room/adv_guild", "down",
        });

        property = ({
            "no_fight",
            "no_sneak",   
            "no_steal",   
            "no_teleport",
        });

        clone_list = ({
            1, 1, "board", "/boards/arch/general", 0,
        });
    }
    ::reset(iArg);
}

void init() {
    if(!this_player()->query_archwiz() || !interactive(this_player())) {
        write("You feel dizzy and fall down the stairs!\n");
        this_player()->move_player("down#/room/wiz/general");
        return;
    }
    else
        ::init();
}
