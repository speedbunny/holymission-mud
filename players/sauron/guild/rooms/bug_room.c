inherit "/room/room";

void reset(int iArg) {
    if(!iArg) {
        set_light(1);
        short_desc = "In a small room.";
        long_desc = "This is a small dusty room underneath the Monk's \
guild where guild members can come and post about bugs in the current \
guild code. Please be as specific as possible with your bug report, \
stating exactly what you did, or what you were doing at the time, where \
you were, what your last command was, and the entire bug message if \
possible.\n\n\tThank you.\n\n";
        dest_dir = ({
            "/players/sauron/guild/rooms/idea_room", "west",
        });
        items = ({});
        clone_list = ({
            1, 1, "board", "/boards/guilds/monk_bug", 0,
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
and so leave west.\n");
        command("west", this_player());
        return;
    }
}
