

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Rasta Market";
    no_castle_flag = 0;
    long_desc = 
        "You walk through the teeming market place of Rasta City, a riot of dark\n"
 + "stalls and bright fabric in primary colors.\n" 
+"To the north you enter the area of Qclxxiv, Rasta's natty dread friend.\n";

    dest_dir = 
        ({
        "players/rasta/room/ground1", "east",
    "players/rasta/room/path11","northwest" })
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

