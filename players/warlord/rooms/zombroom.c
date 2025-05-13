

inherit "room/room";
object o1,o2,o3;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/rooms/zomb");move_object(o1,this_object());}
if (!o2) {o2=clone_object("players/warlord/rooms/zomb");move_object(o2,this_object());}
if (!o3) {o3=clone_object("players/warlord/rooms/zomb");move_object(o3,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This room is a haven for undeads. They look like they are having a party.\n"
        + "Should you really stay in here? \n";
    dest_dir = 
        ({
        "players/warlord/rooms/hounroom", "east",
        });
}

