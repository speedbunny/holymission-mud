

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This area seems to full of banana trees..In the trees there are very large\n"
        + "black objects... One of them is headed down toward you..\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone10", "northeast",
        "players/warlord/stone/stone6", "east",
        "players/warlord/stone/stone2", "southeast",
        });
}

