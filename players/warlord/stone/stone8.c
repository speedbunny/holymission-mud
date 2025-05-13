

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This is a really barren area.. nothing grows here.. you see a lot of\n"
        + "bones around... There is a cave to the east of you with a little light.\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone9", "east",
        "players/warlord/stone/stone7", "west",
        "players/warlord/stone/stone13", "northeast",
        "players/warlord/stone/stone12", "northwest",
        "players/warlord/stone/stone3", "southwest",
        "players/warlord/stone/stone4", "south",
        });
}

