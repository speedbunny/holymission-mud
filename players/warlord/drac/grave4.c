inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "graveyard";
    long_desc = 
        "You are in a dark and creepy graveyard.. there are tombstones north\n"
        + "and east blocking your way... You notice a shadow in the northern area\n";
    dest_dir = 
        ({
        "players/warlord/drac/grave3", "south",
        "players/warlord/drac/grave5", "west",
        });
}
                              
