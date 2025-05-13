inherit "room/room";
    object board;

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "MUD Advertisement room";
    no_castle_flag = 0;
    long_desc = 
        "This is one of the tackiest rooms you have ever seen on the Holy Mission.\n"
        + "Colorful advertisements for all kinds of places are tacked onto the walls\n"
        + "and you think that you have just entered a tourist office. A brown cork board\n"
        + "stands in the middle of the room with notes neatly tacked to it. People use\n"
        + "it to advertise their favourite MUDs, maybe you could make an addition.\n"
        + "\n";
    dest_dir = 
        ({
        "/room/adv_guild", "west",
        });
transfer(clone_object("/boards/mudads"),this_object());
}

query_light() {
    return 1;
}
