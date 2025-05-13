

inherit "room/room";
object o1;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/ptery");move_object(o1,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This area is very hilly. You notice a huge nest above you..\n"
        + "It is a Pterodactyls nest.. so watch out..\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone16", "east",
        "players/warlord/stone/stone14", "west",
        "players/warlord/stone/stone17", "northwest",
        "players/warlord/stone/stone18", "northeast",
        "players/warlord/stone/stone11", "southwest",
        "players/warlord/stone/stone12", "southeast",
        });
}

