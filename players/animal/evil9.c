inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(0);
    short_desc = "Scumfilled tunnel";
    no_castle_flag = 0;
      long_desc = "Scumfilled tunnel\n"
        +"\n" + 
         "    You have entered a small and scummy tunnel.\n"
        + "    The walls are covered with scum. You touch\n"
        + "    one of the walls and pull your hand back\n"
        + "    covered with gooey scum. You hear a faint\n"
        + "    growl coming from the west.\n"
        + "\n";
    dest_dir = 
        ({
        "/players/animal/evil11", "west",
        "/players/animal/evilhall1", "south",
        });
}
 
query_long() {
    return long_desc;
}
query_light() {
    return 0;
}
