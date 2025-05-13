

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Landscape";
    no_castle_flag = 0;
    long_desc = 
        "This landscape consists of rolling green hills, whose granite outcropse are\n"
        + "covered with rastamen buliding spliffs and waiting out the afternoon in good\n"
        + "humor and expectation.\n";
    dest_dir = 
        ({
        "players/rasta/room/ridges1", "west",
        "players/rasta/room/ground1", "north",
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

