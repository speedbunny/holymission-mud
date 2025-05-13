

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Narrow Tunnel";
    no_castle_flag = 0;
    long_desc = 
        "This tunnel is far more damp than the previous one, and it is also\n"
        + "more narrow. Phosphorescent moss lights the tunnel and as you look towards\n"
        + "the west you see that the light continues.\n";
    dest_dir = 
        ({
        "/players/silas/caves/tunnel4", "east",
        "/players/silas/caves/gtunnel2", "west",
        });
    smell = "The mosses give off a vegetative smell.\n";
    ::reset();
    replace_program("room/room");
}


