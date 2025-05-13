

inherit "room/room";

 object bat1,bat2,bat3,bat4,bat5,bat6;
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Ice cavern entrance";
    no_castle_flag = 0;
    long_desc =
	"This ice cave is clearly and enigma to the imagination.\n"
 + "Water seeping through the mountains into the cave, chamber air currents.\n"
 + "and winter's chilling effect have created spectacular ice formations.\n";
    dest_dir =
	({
	"players/rasta/room/top", "east"
	});
bat1 = clone_object("players/rasta/obj/bat");
bat2 = clone_object("players/rasta/obj/bat");
bat3=  clone_object("players/rasta/obj/bat");
bat4 = clone_object("players/rasta/obj/bat");
bat5 = clone_object("players/rasta/obj/bat");
bat6 = clone_object("players/rasta/obj/bat");
move_object(bat1,this_object());
move_object(bat2,this_object());
move_object(bat3,this_object());
move_object(bat4,this_object());
move_object(bat5,this_object());
move_object(bat6,this_object());
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

