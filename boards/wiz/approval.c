inherit "/boards/board";

void reset(int tick) {
    ::reset(tick);
    if(tick) return;

    set_name ("Mentor's Board");
    my_env =  "room/wiz/approval";
}
