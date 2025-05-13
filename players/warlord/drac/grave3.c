inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "graveyard";
    long_desc = 
        "You are in a dark and creepy graveyard.. there are tombstones south and east blocking your way\n";
    dest_dir = 
        ({
        "players/warlord/drac/grave2", "west",
        "players/warlord/drac/grave4", "north",
        });
}
                              
