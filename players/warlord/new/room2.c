

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This is a small yard... There are flowers and smells of spring\n"
        + "all around you... You wish you could stay here...\n";
    dest_dir = 
        ({
        "players/warlord/new/room1","east",
        "players/warlord/new/room5","north",
        });
}

