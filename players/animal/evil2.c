inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "Ladder";
    no_castle_flag = 0;
    long_desc ="Ladder\n"+
          "\n"+ 
          "    A ladder is resting up against the\n"
        + "    east wall here. You cannot see in either\n"
        + "    direction up or down because it is \n"
        + "    too dark. You sense a strong force of evil\n"
        + "    up the ladder. You feel a little afraid.\n"
        + "    You notice on the east wall the part of\n"
        + "    a word '.imes'.\n"
        + "\n";
    dest_dir = 
        ({
        "/players/animal/evil4", "up",
        "/players/animal/evil3", "down",
        "/players/animal/evil20", "west",
        });
}
 
query_long() {
    return long_desc;
}
query_light() {
    return 1;
}
