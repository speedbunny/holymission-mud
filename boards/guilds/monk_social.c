inherit "/boards/board";

void reset(int iArg) {
    ::reset(iArg);
    if(!iArg) {
        set_name("Monk social board");
        my_env = "players/sauron/guild/rooms/social_room";
    }
}
