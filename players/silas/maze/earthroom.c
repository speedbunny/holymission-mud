inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    property = "no_teleport";
    short_desc = "Earthen Room";
    no_castle_flag = 0;
    long_desc = 
        "You have entered a small room which has been hewn out of the rock not too long\n"
        + "ago. Dirt covers the ground and a hole leads downwards into the unknown. You\n"
        + "have a very bad feeling about what lies beneath you and wonder if you should\n"
        + "head back into the maze.\n";
    dest_dir = 
        ({
        "/players/silas/maze/hole1", "down",
        "/players/silas/maze/maze12", "north",
        });
    smell = "An ungodly stench rises from below.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
