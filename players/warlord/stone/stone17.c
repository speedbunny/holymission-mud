

inherit "room/room";
object o1;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/monsters/steg");move_object(o1,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This room is occupied by a very pissed stegasaurus. Someone\n"
        + "stole his plant dinner and he thinks its you.... Run while you can..\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone14", "southwest",
        "players/warlord/stone/stone15", "southeast",
        "players/warlord/stone/stone19", "northeast",
        "players/warlord/stone/stone18", "east",
        });
}

