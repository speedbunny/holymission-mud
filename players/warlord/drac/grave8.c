inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "graveyard";
    long_desc = 
        "You are in a dark and creepy graveyard.. there are tombstones north \n"
        + "and south blocking your way.. The shadow becomes more vivid now.. its a ...\n";
    dest_dir = 
        ({
        "players/warlord/drac/grave7", "west",
        "players/warlord/drac/grave9", "east",
        });
}
                             
