

inherit "room/room";
object o1,o2;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/monsters/lizard");move_object(o1,this_object());}
if (!o2) {o2=clone_object("players/warlord/monsters/lizard");move_object(o2,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This area is a bit swampy and the creatures here seem to be  pretty rampid.. Especially the lizards...\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone1", "southwest",
        "players/warlord/stone/stone8", "north",
        "players/warlord/stone/stone9", "northeast",
        "players/warlord/stone/stone7", "northwest",
        "players/warlord/stone/stone3", "west",
        });
}

