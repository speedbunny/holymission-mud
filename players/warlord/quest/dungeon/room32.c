

inherit"players/warlord/NEWSTUFF/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "forest";
    no_castle_flag = 0;
    long_desc = 
        "You starting to get excited for some reason.. The light is bright and \n"
        + "beautiful. You start to hear sounds coming from the northwest.\n";
    dest_dir = 
        ({
        "players/warlord/quest/dungeon/room31", "north",
        "players/warlord/quest/dungeon/room18", "west",
        });
}

