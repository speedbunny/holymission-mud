

inherit "room/room";
object o1,o2,o3;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/rooms/slord");move_object(o1,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "Now you've done it.. you've entered the Skeleton Lord's\n"
        + "chambers.. you might as well say your prayers.....\n";
    dest_dir = 
        ({
        "players/warlord/rooms/skel3", "west",
        });
}

