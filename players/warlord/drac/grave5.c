inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "graveyard";
    long_desc = 
        "You are in a dark and creepy graveyard.. there are tombstones north \n"
        + "and south blocking your way....\n";
    dest_dir = 
        ({
        "players/warlord/drac/grave4", "east",
        "players/warlord/drac/grave6", "west",
        });
}
                              
