inherit "/obj/board";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_file("players/topaz/logs/board");
    set_name("Topaz's Board");
    set_short("A board where you can post if you want to");
}
