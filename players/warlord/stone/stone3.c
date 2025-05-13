

inherit "room/room";
object o1,o2,o3;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/monsters/bird");move_object(o1,this_object());}
if (!o2) {o2=clone_object("players/warlord/monsters/bird");move_object(o2,this_object());}
if (!o3) {o3=clone_object("players/warlord/monsters/bird");move_object(o3,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "The noise of all the birds in this area is deafening. You can barely\n"
        + "hear yourself think; they seem to be very hungry.\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone7", "north",
        "players/warlord/stone/stone1", "south",
        "players/warlord/stone/stone2", "west",
        "players/warlord/stone/stone4", "east",
        "players/warlord/stone/stone6", "northwest",
        "players/warlord/stone/stone8", "northeast",
        });
}

