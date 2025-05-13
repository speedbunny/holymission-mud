

inherit "room/room";

 object buzz1,buzz2,buzz3,sign;
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Buzzard grounds";
    no_castle_flag = 0;
    long_desc = 
        "Giant turkey buzzards swoop over the ground, perhaps drawn by the spicy scent\n"
        + "of stewing goat and I-tal food.\n";
    dest_dir = 
        ({
        "players/rasta/room/scape", "south",
        "players/rasta/room/market", "west",
        });
buzz1 = clone_object("players/rasta/obj/buzzard");
buzz2 = clone_object("players/rasta/obj/buzzard");
buzz3=clone_object("players/rasta/obj/buzzard");
 if (!sign) {sign=clone_object("players/rasta/obj/moved");
             move_object(sign,this_object());}
move_object(buzz1,this_object());
move_object(buzz2,this_object());
move_object(buzz3,this_object());
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

