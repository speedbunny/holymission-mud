

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    smell="You smell Beer!!";
    short_desc = "hallway";
    no_castle_flag = 0;
    long_desc = 
        "This is a beautiful hallway with a pleasant smell in it.\n"
        + "You really want to know where the smell is coming from.\n";
    dest_dir = 
        ({
        "players/warlord/rooms/hallway3", "east",
        "players/warlord/rooms/hallwaye", "west",
        "players/warlord/rooms/room2", "north",
        "players/warlord/rooms/room3", "south",
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

