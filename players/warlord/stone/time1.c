

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This is the entrance to the stone age. Rememeber that dinosaurss\n"
        + "rule the land here so don't get stepped on. To go there continue \n"
        + "north. If you're smart head back south.\n";
    dest_dir = 
        ({
        "players/warlord/rooms/entrance", "south",
                "players/warlord/stone/stone1","north",
        });
}

