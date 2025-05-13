

inherit "room/room";
object o1;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/monsters/mamm");move_object(o1,this_object());}
    if (arg) return;

    set_light(1);
short_desc="A barren room full of Dredd";
    no_castle_flag = 0;
    long_desc = 
        "This area is very barren and you find out very quickly\n"
        + "There is a huge wooly mammoth charging at you!!!\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone18", "northwest",
        "players/warlord/stone/stone13", "southeast",
        "players/warlord/stone/stone15", "west",
        "players/warlord/stone/stone12", "southwest",
        });
}

