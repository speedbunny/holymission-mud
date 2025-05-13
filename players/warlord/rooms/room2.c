

inherit "room/room";
object o1,o2,o3;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/monsters/guard");move_object(o1,this_object());}
if (!o2) {o2=clone_object("players/warlord/monsters/guard");move_object(o2,this_object());}
if (!o3) {o3=clone_object("players/warlord/monsters/guard");move_object(o3,this_object());}
    if (arg) return;

    set_light(2);
    short_desc = "room2";
    no_castle_flag = 0;
    long_desc = 
        "This is the Guard's Bedrooms.. Please leave before your caught!!!\n";
    dest_dir = 
        ({
        "players/warlord/rooms/hallway2", "south",
        });
}

query_light() {
    return 2;
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

