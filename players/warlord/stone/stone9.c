

inherit "room/room";
object o1,o2;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/monsters/caveman");move_object(o1,this_object());}
if (!o2) {o2=clone_object("players/warlord/monsters/caveman");move_object(o2,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "You have stubled into a cave with a small fire.. You see large cavemen\n"
        + "sitting around it chanting something.. They stop the minute they see you \n"
        + "and start heading toward you...\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone13", "northwest",
        "players/warlord/stone/stone8", "west",
        "players/warlord/stone/stone4", "southwest",
        });
}

