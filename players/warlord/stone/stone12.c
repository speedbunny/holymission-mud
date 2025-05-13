

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This is a very hilly and rocky area.. The whole area seems to be moving..\n"
        + "You notice that someone or something is moving below our feet..\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone13", "east",
        "players/warlord/stone/stone16", "northeast",
        "players/warlord/stone/stone15", "northwest",
        "players/warlord/stone/stone8", "southeast",
        "players/warlord/stone/stone7", "southwest",
        "players/warlord/stone/stone11", "west",
        });
}

