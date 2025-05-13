

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This area is rather plush with vegatation, but here doesn't seem \n"
        + "to be any creatures around.. You feel safe here..\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone3", "south",
        "players/warlord/stone/stone6", "west",
        "players/warlord/stone/stone8", "east",
        "players/warlord/stone/stone12", "northeast",
        "players/warlord/stone/stone11", "northwest",
        "players/warlord/stone/stone2", "southeast",
        "players/warlord/stone/stone4", "southwest",
        });
}

