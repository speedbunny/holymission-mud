

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Grand hallway";
    no_castle_flag = 0;
    long_desc = 
"This is the grand hallway. You are honored by its beauty. To the\n"+
"west is the weaponary and to the north is the armoury. The \n"+
"castle hallway continues to the east.\n";
    dest_dir = 
        ({
        "players/warlord/rooms/hallwaye", "east",
        "players/warlord/road2", "south",
        "players/warlord/rooms/armoury","north",
        "players/warlord/rooms/weaponary","west",
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

