inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "graveyard";
    long_desc = 
        "You are in a dark and creepy graveyard.. there are tombstones north and west \n"
        + "blocking your way.. You feel a stange presence near.....\n";
    dest_dir = 
        ({
        "players/warlord/drac/grave6", "south",
        "players/warlord/drac/grave8", "east",
        });
}
