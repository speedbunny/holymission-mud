inherit "/room/room";

void reset(int iArg) {
    if(!iArg) {
        set_light(1);

        short_desc = "The LPC board room";
        long_desc = "This is the LPC discussion room.\n";

        dest_dir=({
            "/room/wiz/general", "north",
        });

        property = ({
            "no_fight",           
            "no_sneak",              
            "no_steal",   
            "no_teleport",
        });
        
        clone_list = ({
            1, 1, "board", "/boards/wiz/lpc" , 0,
        });
    }
    ::reset(iArg);
}

void init() {
    if(!this_player()->query_immortal() || !interactive(this_player())) {
        write("You feel dizzy and run outside for fresh air.\n");
        this_player()->move_player("north#/room/wiz/general");
        return;
    }
    else
        ::init();
}
