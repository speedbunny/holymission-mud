

inherit "room/room";
object s;

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Narrow Lane";
    no_castle_flag = 0;
    long_desc = 
        "This lane is narrow and infrequently traveled except by flocks of\n"
        + "goats and the inter-village Rasta vans that hurl passengers along with\n"
        + "breakneck abandon.\n";
    dest_dir = 
        ({
        "players/rasta/room/yard", "north",
   "players/rasta/room/trench", "south",
        });

if (!s)     
    s = clone_object("players/rasta/obj/sign2");
  move_object(s,this_object());
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

