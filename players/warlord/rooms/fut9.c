

inherit "room/room";
object o1,o2,o3;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/monsters/bas");
move_object(o1,this_object());}
if (!o2) {o2=clone_object("players/warlord/monsters/bas");
move_object(o2,this_object());}
if (!o3) {o3=clone_object("players/warlord/monsters/lbas");
move_object(o3,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "Basilisk's room.";
    no_castle_flag = 0;
    long_desc = 
        "You have not listened to any warnings and have entered the \n"
       +"the basilisks' room. There is a sign on the wall.\n";
    items = ({
            "sign","Do not go west or southwest. Great danger there.\n",
            });
    dest_dir = 
        ({
        "players/warlord/rooms/fut6", "northwest",
        "players/warlord/rooms/fut7", "west",
        "players/warlord/rooms/fut10", "southwest",
        });
}
