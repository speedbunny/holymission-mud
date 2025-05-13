

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This is a hallway that extends to the north... You can barely see\n"
        + "the end of it...\n";
    dest_dir = 
        ({
        "players/warlord/new/room1","west",
        "players/warlord/new/room6","north",
        });
}

