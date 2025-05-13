

inherit "room/room";
object o1;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/rooms/mlord");move_object(o1,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "Are you crazy you just entered the almighty Mummy lord room..\n"
        + "If he sees you here he will bandage you up and keep ypou here forever!!\n";
    dest_dir = 
        ({
        "players/warlord/rooms/slordroom", "south",
        "players/warlord/rooms/grave1", "portal",
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

