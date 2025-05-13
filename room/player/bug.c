inherit "/room/room";

void reset(int iArg) {
    if(!iArg) {
        set_light(1);

        short_desc = "Bug Room";
        long_desc = "This is a bug room. Several of them are crawling \
around the mud and need to be squished. Please let us know where you see \
these nasty bugs and any special actions you took to make them happen.\n";

        dest_dir = ({
            "/room/adv_guild", "northeast"
        });

        property = ({
            "no_fight",
            "no_sneak",
            "no_steal",
            "no_teleport",
        });

        clone_list = ({
            1, 1, "board", "/boards/player/bug" , 0,
        });
    }
    ::reset(iArg);
    replace_program("/room/room");
}
