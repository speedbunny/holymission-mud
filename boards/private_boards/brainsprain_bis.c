inherit "/boards/board";

void reset(int tick) {
    ::reset(tick);
    if(tick)
        return;

    set_name("Townpath Town Board");
    my_env = "players/brainsprain/bis/rooms/town_room";
}
