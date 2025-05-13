inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    property = "no_teleport";
    short_desc = "Hole";
    no_castle_flag = 0;
    long_desc = 
        "You are slowly climbing down a hole. Underneath you can hear hungry\n"
        + "growls and the cracking of bones. Climbing down further would not be a very\n"
        + "smart idea but I'm sure that whatever is down there wouldn't mind your visit...\n";
    dest_dir = 
        ({
        "/players/silas/maze/earthroom", "up",
        "/players/silas/maze/hole2", "down",
        });
    smell = "An ungodly stench rises from below.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 0;
}
