

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Dense vegetation";
    no_castle_flag = 0;
    long_desc = 
        "You have entered a time when the ground is very moist " +
        "and the earth is young. You can see vegatation all around. " +
        "The sounds of death are all around and you feel uneasy.\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone3", "north",
        "players/warlord/stone/stone2", "northwest",
        "players/warlord/stone/stone4", "northeast",
                "players/warlord/stone/time1","south",
        });
}

