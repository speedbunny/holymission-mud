inherit "/room/room";

void reset(int iArg) {
    if(!iArg) {
        set_light(1);

        short_desc = "Wizard's flame room";
        long_desc = "You are in the wizard's flame room. The hottest \
discussions will be fought out here. Remember, you can't carve your \
way to success without cutting remarks.\n";

        dest_dir = ({
            "/room/wiz/general", "up"
        });

        items = ({
           "flame", "Mangla appears and FLAMES you",
        });

        property = ({
            "no_fight",
            "no_sneak",   
            "no_steal",   
            "no_teleport",
        });

        clone_list = ({
            1, 1, "board", "/boards/wiz/flame" , 0,
        });
    }
    ::reset(iArg);
}

void init() {
    if(!this_player()->query_immortal() || !interactive(this_player())) {
        write("You feel dizzy and run up for fresh air.\n");
        this_player()->move_player("up#/room/wiz/general");
        return;
    }
    else
        ::init();
}
