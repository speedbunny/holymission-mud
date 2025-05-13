inherit "/room/room";

void reset(int iArg) {
    if(!iArg) {
        set_light(1);
        short_desc = "In a small room.";
        long_desc = "This is a small room above the Monk's guild which \
is reserved for our guild members to rest and relax. It is also \
intended as a room where they can leave equipment to help other guild \
members, especially our newer, and lower level guild members. Please \
uphold the pride and honour of our guild and do not take equipment from \
this room to give to non Monks (including your second characters). \
Thank you.\n";
        dest_dir = ({
            "/players/whisky/guild/room/c10", "down",
        });
        items = ({});
         property = ({
            "no_clean_up",
            "no_fight",
        });
        clone_list = ({
            1, 1, "board", "/boards/guilds/monk_social", 0,
        });
    }
    ::reset(iArg);
}

void init() {
    ::init();
    if(this_player()->query_real_guild() != 7 &&
       !this_player()->query_immortal() &&
       !this_player()->query_testchar()) {
        write("You realise that there is nothing interesting up here \
and so leave down.\n");
        command("down", this_player());
        return;
    }
}
