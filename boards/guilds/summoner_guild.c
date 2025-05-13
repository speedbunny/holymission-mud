inherit "/boards/board";

int valid_remove(object oWho, int iNo) {
    if(oWho->query_real_name() == "/guild/master"->query_wiz(9))
        return 1;
    else
        return ::valid_remove(oWho, iNo);
}

void reset(int iArg) {
    ::reset(iArg);
    if(!iArg) {
        set_name("Summoner's Guild Board");
        my_env = "players/redsexy/guild/rooms/lounge";
    }
}
