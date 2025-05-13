inherit "/room/room";

void reset(int iArg) {
    if(!iArg) {
        set_light(1);

        short_desc = "Ideas Room";
        long_desc = "This is an idea room. If you have some ideas, or \
the arches have ideas they want input on, they will be posted here to \
keep the main board clearer.\n";

        dest_dir = ({
            "/room/wiz/general", "northeast"
        });

        items = ({
        });

        property = ({
            "no_fight",           
            "no_sneak",              
            "no_steal",   
            "no_teleport",
        });

        clone_list = ({
            1, 1, "board", "/boards/wiz/idea" , 0,
        });
    }
    ::reset(iArg);
}

void init() {
    if(!this_player()->query_immortal() || !interactive(this_player())) {
        write("You feel dizzy and run northeast for fresh air.\n");
        this_player()->move_player("northeast#/room/wiz/general");
        return;
    } 
    else
        ::init();
}
