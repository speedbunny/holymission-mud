

#include "path.h"
inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "room3";
    no_castle_flag = 0;
    long_desc = 
        "The path turns sandy here. You smell a fresh breeze.\n"
+ "There are rocks to the north and mountains to the south.\n";
    dest_dir = 
        ({
        "/players/talagan/room/room2", "west",
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

