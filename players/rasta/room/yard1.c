

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A Yard";
    no_castle_flag = 0;
    long_desc = 
        "This is a huge yard in front of a little chapel, which is gray-roofed and\n"
        + "sided with sheetrock. Light in the stained-glass windows flickers from the\n"
        + "dozens of long candles and tapers burn silently.\n";
    dest_dir = 
        ({
        "players/rasta/room/ital1", "north",
        "players/rasta/room/dustroa1", "west",
        "players/rasta/room/lane1", "south",
        });
}

query_light() {
    return 1;
}
query_room_maker() {
    return 101;
}

/*
    remove the comments around the "room is modified()" code
    below to prevent changes you have done to this room to
    to be lost by using the room maker
*/
/*
room_is_modified() {
    return 1;
}
*/

/*
 make your additions below this comment, do NOT remove this comment
--END-ROOM-MAKER-CODE--
*/

