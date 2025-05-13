

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This part of the land is rather moist and there is a small swamp\n"
        + "in front of you.. You notice a couple lizardman in front of yu..\n"
        + "They turn around just as yu spot them.. They charge for you..\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone14", "northeast",
        "players/warlord/stone/stone11", "east",
        "players/warlord/stone/stone6", "southeast",
        "players/warlord/stone/stone5", "southwest",
        });
}

