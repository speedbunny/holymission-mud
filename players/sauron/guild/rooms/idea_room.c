inherit "/room/room";

void reset(int iArg) {
    if(!iArg) {
        set_light(1);
        short_desc = "In a small room.";
        long_desc = "This is a small dusty room underneath the Monk's \
guild where guild members can come and post their ideas and suggestions \
about the guild recoding/restructuring that is about to take place. \
Please make sure that you have all your ideas and thoughts sorted out in \
your own mind before you start writing so that you don't forget anything \
- I would prefer to only have 1 note from each member of the guild \
stating their suggestions.\n\n\tThank you.\n\n";
        dest_dir = ({
            "/players/whisky/guild/room/c10", "up",
            "/players/sauron/guild/rooms/bug_room", "east",
        });
        items = ({});
        clone_list = ({
            1, 1, "board", "/boards/guilds/monk_idea", 0,
        });
    }
    ::reset(iArg);
}

void init() {
    ::init();
    if(this_player()->query_real_guild() != 7 &&
       !this_player()->query_immortal() &&
       !this_player()->query_testchar()) {
        write("You realise that there is nothing interesting down here \
and so leave up.\n");
        command("up", this_player());
        return;
    }
}
