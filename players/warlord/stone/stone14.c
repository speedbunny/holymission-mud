

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This place is a fairly rocky area. You hear some weird noises\n"
        + "coming from all around you. There is a triceratops eating grass here.\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone17", "northeast",
        "players/warlord/stone/stone15", "east",
        "players/warlord/stone/stone11", "southeast",
        "players/warlord/stone/stone10", "southwest",
        });
}

