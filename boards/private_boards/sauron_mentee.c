inherit "/boards/board";

void reset(int tick) {
    ::reset(tick);
    if(!tick) {
        set_name("Sauron's Mentee Board");
        my_env="players/sauron/mentor/room/menteeRoom";
    }
}
