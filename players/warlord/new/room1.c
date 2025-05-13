

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Main hall";
    no_castle_flag = 0;
    long_desc = 
        "This looks as though it could be the entrance to HELL!!!\n"
        + "It may be the heat and the smell that are giving it away...\n";
    dest_dir = 
        ({
/*
        "players/slayer/castlerooms/hell1", "down",
*/
        "players/warlord/new/room2","west",
        "players/warlord/new/room3","north",
        "players/warlord/new/room4","east",
        "players/warlord/rooms/entrance","out",
        });
}

