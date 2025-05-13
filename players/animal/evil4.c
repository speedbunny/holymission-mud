inherit "room/room";
 
reset(arg) {
    if (arg) return;
 
    set_light(0);
    short_desc = "Short passage";
    no_castle_flag = 0;
    long_desc ="Short passage" +
	"\n\n" +
          "    You have made it to a small and dirty room.\n"
        + "    You smell a feline scent to the north.\n"
        + "    You can also smell the stench of death from the north.\n"
        + "\n";
    dest_dir =
        ({
        "/players/animal/evil2", "down",
        "/players/animal/evil5", "north",
        });
}
 
query_light() {
    return 0;
}
 
