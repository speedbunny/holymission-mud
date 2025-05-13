inherit "/room/room";


void reset(int iArg) {
    if(!iArg) {
        set_light(1);

        short_desc = "New area approval room";
        long_desc = "This room is for the new areas awaiting to be \
approved.  Mentor's are to post here when their student's areas are ready \
to be examined. Use the 'mentors' command to view the current list of \
Mentors and their students.\nTo the north is the mentor wanted board.\n";

        dest_dir = ({
            "/room/wiz/general", "west",
            "/room/wiz/mentor",  "north"
        });

        property = ({
            "no_fight",
            "no_sneak",   
            "no_steal",   
            "no_teleport",
        });

        clone_list = ({
            1, 1, "board", "/boards/wiz/approval", 0,
        });
    }
    ::reset(iArg);
}

void init(){
    if(!this_player()->query_immortal() || !interactive(this_player())) {
        write("You feel dizzy and run north for fresh air.\n");
        this_player()->move_player("north#/room/wiz/mentor");
        return;
    }
    else
        ::init();
}
