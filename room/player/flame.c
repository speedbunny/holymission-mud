inherit "/room/room";

void reset(int iArg) {
    if(!iArg) {
        set_light(1);

        short_desc = "Players flame room";
        long_desc = "This is the players flame room where players come \
if they want to complain about something (or someone).\n";

        dest_dir = ({
            "/room/adv_guild","up"
        });

        property = ({
            "no_fight",
            "no_sneak",
            "no_steal",
            "no_teleport",
        });

        clone_list = ({
            1, 1, "board", "/boards/player/flame" , 0,
        });
    }
    ::reset(iArg);
    replace_program("/room/room");
}
