inherit "/boards/board";

void long() {
    if(this_player()->query_archwiz() && interactive(this_player()))
        ::long();
    else
        write("Illegal access! (logged)\n");
}
 
void reset(int iArg) {
    ::reset(iArg);
    if(!iArg) {
        set_name("Archwiz board");
        my_env="room/arch/general";
    }
}
 
void init() {
    ::init();

    if(!interactive(this_player())) 
        destruct(this_player()); 
    else if(!this_player()->query_archwiz()) {
        this_player()->move_player("X#/room/church");
        write("Illegal access! (logged)\n");
    }
}
