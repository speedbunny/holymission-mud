

inherit "room/room";
object o1,o2;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/monsters/guard");move_object(o1,this_object());}
if (!o2) {o2=clone_object("players/warlord/monsters/guard");move_object(o2,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "Guard's Bedroom";
    no_castle_flag = 0;
    long_desc = 
        "This is the Guard's bedroom.. Please leave before your caught !!\n";
    dest_dir = 
        ({
        "players/warlord/rooms/hallway2", "north",
        });
}

