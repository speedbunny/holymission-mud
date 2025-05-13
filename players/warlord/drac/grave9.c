inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "graveyard";
    long_desc = 
        "You are in a dark and creepy graveyard.. there are tombstones east and \n"
        + "south of you blocking your way.. and a very large structure in front of\n"
        + "you... it looks like a tower.. do you dare enter...\n";
    dest_dir = 
        ({
        "players/warlord/drac/tower1", "enter",
        "players/warlord/drac/grave8", "west",
        });
}
                              
