

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Dusty Road";
    no_castle_flag = 0;
    long_desc = 
        "It's hard to keep your eyes on the undulating red dirt road.\n";
    dest_dir = 
        ({
     "players/rasta/room/bulletin", "west",
        "players/rasta/room/yard", "east",
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

