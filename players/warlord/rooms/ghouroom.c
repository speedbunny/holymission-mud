

inherit "room/room";
object o1,o2,o3;

reset(arg) {

if (!o1) {o1=clone_object("players/warlord/rooms/ghoul");move_object(o1,this_object());}
if (!o2) {o2=clone_object("players/warlord/rooms/ghoul");move_object(o2,this_object());}
if (!o3) {o3=clone_object("players/warlord/rooms/ghoul");move_object(o3,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This room has feels very uneasy...Almost too eerie for most..\n"
        + "There are a lot of apparitions floating about the room.....\n"
        + "maybe you should turn back.. it doesn't look safe from here on in!!\n";
    dest_dir = 
        ({
        "players/warlord/rooms/hall1", "north",
        "players/warlord/rooms/grimroom", "south",
        });
}

