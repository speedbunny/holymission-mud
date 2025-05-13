

inherit "room/room";
object o1,o2,o3;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/rooms/monsters/mummy2");move_object(o1,this_object());}
if (!o2) {o2=clone_object("players/warlord/rooms/monsters/ghoul2");move_object(o2,this_object());}
if (!o3) {o3=clone_object("players/warlord/rooms/monsters/zomb2");move_object(o3,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This room is filled with a lot of undead creatures, you hear them discussing\n"
        + "how much they hate mortals.. They also talk about killing all mortals and  \n"
        + "ruling the MUD someday..Oh no they have spotted you..\n";
    dest_dir = 
        ({
        "players/warlord/rooms/zombroom2", "north",
        "players/warlord/rooms/glordroom", "east",
        });
}

