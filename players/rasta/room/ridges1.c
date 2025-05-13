

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Cruising along ridges";
    no_castle_flag = 0;
    long_desc = 
        "Cruising along inland ridges one can see the impossibly deep azure of the ocean\n"
        + "on the other side of the hills.\n";
    dest_dir = 
        ({
    "players/rasta/room/trench1","north",
        "players/rasta/room/scape1", "east",
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

