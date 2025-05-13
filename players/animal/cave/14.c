inherit "room/room";
 
reset(arg) {
    if (arg) return;
 
    ::reset(arg);
/*  set_outdoors(0);   */
    set_light(1);
    short_desc = "Cave of light";
    no_castle_flag = 0;
    long_desc = 
        "Magical cave\n\n"
        + "     You seem to be in a magical cave. The cave walls all\n"
        + "     emit a bright white light. The light is so bright that\n"
        + "     no light source is needed here.\n\n";
    dest_dir = 
        ({
        "players/animal/cave/3", "south",    
        "players/animal/cave/1", "east",
        "players/animal/cave/15","west",
        });
}
 
query_long() {
    return long_desc;
}
query_outdoorness() {
    return 0;
}
query_light() {
    return 1;
}
realm() { return "NT"; }
