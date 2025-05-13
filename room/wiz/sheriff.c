inherit "/room/room";

void reset(int iArg) {
    if(!iArg) {
        set_light(1);

        short_desc = "Wizard Sheriff's Office";
        long_desc = "\tThe Holy Mission Wizard Sheriff's Office\n\
You are in the wizard sheriff's office for the law enforcement of Holy \
Mission.  There is a large table alone near the south wall with wooden \
chairs around it.  There is an unusual spiral staircase located at the \
center of the room. A magical green field covers the steps, pulsing with \
power.\n";

        dest_dir = ({
           "/room/player/sheriff", "up",
        });

        items = ({
            "steps",     "The steps of a spiral staircase",
            "field",     "A magical green field",
            "power",     "You cannot see power, but you know it's there",
            "wall",      "The walls",
            "table",     "A table for group discussions",
            "chairs",    "Chairs around the table",
            "staircase", "A winding spiral staircase",
            "office",    "The Holy Mission Wizard Sheriff's Office",
        });

        property = ({ 
            "no_fight",
            "no_sneak",
            "no_steal",
            "no_teleport",
        });

        clone_list = ({
            1, 1, "board", "/boards/wiz/sheriff", 0,
            2, 1, "book",  "/room/wiz/sheriff_book", 0,
        });
    }
    ::reset(iArg);
}

void init() {
    if(!this_player()->query_immortal() || !interactive(this_player())) {
        write("You feel dizzy and run outside for fresh air.\n");
        this_player()->move_player("up#/room/player/sheriff");
        return;
    }
    else
        ::init();
}
