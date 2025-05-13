inherit "room/room";
 
reset(arg) {
    if (arg) return;
 
    ::reset(arg);
    set_outdoors(1);
    set_light(1);
    short_desc = "Guild";
    no_castle_flag = 0;
    long_desc =
        "Guild hall\n"
        + "\n"
        + "     This is a soon to be completed guild hall. The guild\n"
        + "     that will be moving here is the monster guild. You will\n"
        + "     hopefully like thie guild. It will be posted when it\n"
        + "     is ready to open. DO NOT bother me too much cause it will\n"
        + "     only take me longer to finish it.\n\n";
        items =
        "guild","This is a soon to be completed guild",
    dest_dir =
        ({
        "players/animal/shops/shop_street2", "east",
        });
}
 
query_long() {
    return long_desc;
}
query_outdoorness() {
    return 4;
}
query_light() {
    return 1;
}
