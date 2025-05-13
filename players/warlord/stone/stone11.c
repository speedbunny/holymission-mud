

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "You find a nice tranquil pond here.. The vegetation is beautiful and \n"
        + "you feel at ease...There is a lot of noise coming from all directions\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone14", "northwest",
        "players/warlord/stone/stone15", "northeast",
        "players/warlord/stone/stone10", "west",
        "players/warlord/stone/stone12", "east",
        "players/warlord/stone/stone7", "southeast",
        "players/warlord/stone/stone6", "southwest",
        });
}

