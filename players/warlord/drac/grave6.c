inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "graveyard";
    long_desc = 
"You are in a dark and creepy graveyard.. there are tombstones west and south\n"
        + "blocking your way....\n";
    dest_dir = 
        ({
        "players/warlord/drac/grave7", "north",
        "players/warlord/drac/grave5", "east",
        });
}
