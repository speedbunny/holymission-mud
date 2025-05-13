

inherit "room/room";
object o1;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/tiger");move_object(o1,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "You have stumbled upon the lair of one mean Saber Tooth Tiger..\n"
        + "He looks happy now because lunch just came his way....\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone10", "northwest",
        "players/warlord/stone/stone11", "northeast",
        "players/warlord/stone/stone5", "west",
        "players/warlord/stone/stone7", "east",
        "players/warlord/stone/stone2", "south",
        "players/warlord/stone/stone3", "southeast",
        });
}

