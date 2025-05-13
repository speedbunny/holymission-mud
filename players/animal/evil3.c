inherit "room/room";
 
reset(arg) {
    if (arg) return;
 
    set_light(0);
    short_desc = "Ladder bottom";
    no_castle_flag = 0;
    long_desc ="Bottom of ladder\n\n" +
        "   The ladder is resting here against the wall. This small and damp\n"
      + "   room smells like rotting eggs. Off to the south you hear a faint\n"
      + "   cackling and you see odd flashes of light from that direction.\n\n";
    dest_dir =
        ({
        "/players/animal/evil2", "up",
        "/players/animal/evil6", "south",
        });
}
 
query_long() {
    return long_desc;
}
query_light() {
    return 0;
}
