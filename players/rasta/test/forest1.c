

inherit "room/room";

 object moth1,moth2,moth3;
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "mangrove forest";
    no_castle_flag = 0;
    long_desc =
"You are in a dense tropical rain forest.\n"
+"\n";
    dest_dir =
	({
	"players/rasta/room/surray", "south"
	});
moth1 = clone_object("players/rasta/obj/mosquito");
moth2= clone_object("players/rasta/obj/mosquito");
moth3=clone_object("players/rasta/obj/mosquito");
move_object(moth1,this_object());
move_object(moth2,this_object());
move_object(moth3,this_object());
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

 