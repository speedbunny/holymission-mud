inherit "/room/room";

void reset(int iArg) {
    if(!iArg) {
        set_light(1);

        short_desc = "The wiz board room.";
        long_desc = "This is the wizard board room.\n\
Feel free to discuss your wizardly opinions here.\n";

        dest_dir=({
            "/room/adv_guild",       "north",
            "/room/wiz/approval",    "east",
            "/room/wiz/lpc",         "south",
            "/room/wiz/idea",        "southwest",
            "/room/wiz/coding_room", "up",
            "/room/wiz/flame",       "down",
        });

        property = ({
            "no_fight",
            "no_sneak",   
            "no_steal",   
            "no_teleport",
        });

        clone_list = ({
            1, 1, "board", "/boards/wiz/general", 0,
        });
    }
    ::reset(iArg);
}
 
void init() {
    if(!this_player()->query_immortal() || !interactive(this_player())) {
        write("You feel dizzy and run outside for fresh air.\n");
        this_player()->move_player("north#/room/adv_guild");
        return;
    }   
    else
        ::init();
}

