

inherit "room/room";
object o1,o2;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/monsters/cobra");
move_object(o1,this_object());}
if (!o2) {o2=clone_object("players/warlord/monsters/cobra");
move_object(o2,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "The sorceror's snake room.";
    no_castle_flag = 0;
    long_desc = 
        "This room is the Sorceror's snake room. You were warned about coming\n"
       +"to this room. You are in deep trouble!!\n";
    dest_dir = 
        ({
        "players/warlord/rooms/fut5", "northeast",
        "players/warlord/rooms/fut10", "southeast",
        "players/warlord/rooms/fut7", "east",
        });
}



