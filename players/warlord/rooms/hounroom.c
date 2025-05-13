

inherit "room/room";
object o1,o2;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/rooms/hellhound");move_object(o1,this_object());}
if (!o2) {o2=clone_object("players/warlord/rooms/hellhound");move_object(o2,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This room if filled with Large Hellhounds.. Don't mess with them they\n"
        + "have teeth that will shred your puny armor.\n";
    dest_dir = 
        ({
        "players/warlord/rooms/zombroom", "west",
        "players/warlord/rooms/hall2", "north",
        "players/warlord/rooms/hall1", "south",
        });
}

