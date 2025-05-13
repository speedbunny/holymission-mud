

inherit "room/room";
object o1,o2;

reset(arg) {
if(!o1) {o1=clone_object("players/warlord/monsters/rat");move_object(o1,this_object());}
if (!o2) {o2=clone_object("players/warlord/monsters/rat");move_object(o2,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "Moist and humid jungle";
    no_castle_flag = 0;
    long_desc = 
    "This is a rather dry and arrid part. You can almost swear"+
    " you \n can see things moving by your feet.\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone1", "southeast",
        "players/warlord/stone/stone3", "east",
        "players/warlord/stone/stone7", "northeast",
        "players/warlord/stone/stone6", "north",
        "players/warlord/stone/stone5", "northwest",
        });
}

