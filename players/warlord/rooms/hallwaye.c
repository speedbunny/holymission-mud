

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "long hallway";
    no_castle_flag = 0;
    long_desc = 
        "This is a long hallway that seems to go on forever.\n";
    dest_dir = 
        ({
        "players/warlord/rooms/room", "west",
        "players/warlord/rooms/hallway2", "east",
        });
}

