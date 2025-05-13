

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "You see a huge oil puddle here; it seems to be moving uphill. How\n"
        + "though...hmm...it looks as if its taking a humanoid shape...\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone16", "northwest",
        "players/warlord/stone/stone9", "southeast",
        "players/warlord/stone/stone8", "southwest",
        "players/warlord/stone/stone12", "west",
        });
}

