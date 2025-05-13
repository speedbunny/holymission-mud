inherit "/room/room";

void reset(int iArg) {
    if(!iArg) {
        set_light(1);

        short_desc = "Mentor wanted room";
        long_desc = "This room is designed so that Apprentices looking for \
a mentor can have some help in locating one. Apprentices are encouraged to \
leave a note listing some of thier experience with code and MUDs and \
Mentors are encouraged to leave notes when they feel they might want an \
apprentice.\n\
The adventurer's guild is to the northwest and the area approval board \
is to the south.\n";

        dest_dir = ({
            "/room/adv_guild",    "northwest",
            "/room/wiz/approval", "south"
        });

        property = ({
            "no_fight",
            "no_sneak",   
            "no_steal",   
            "no_teleport",
        });

        clone_list = ({
            1, 1, "board", "/boards/wiz/mentor", 0,
        });
    }
    ::reset(iArg);
}

void init() {
    if(!this_player()->query_immortal() || !interactive(this_player())) {
        write("You feel dizzy and run out for fresh air.\n");
        this_player()->move_player("northwest#/room/adv_guild");
        return;
    }
    else
        ::init();
}
