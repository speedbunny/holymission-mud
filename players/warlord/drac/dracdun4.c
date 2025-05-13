

inherit "room/room";
object o1;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/rooms/neatfreak");move_object(o1,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    long_desc = 
        "This is a rather clean dungeon. The reason being the large monster chained\n"
        + "in the corner is a neat freak, but hates visitors. You'd better leave!!!\n";
    dest_dir = 
        ({
        "players/warlord/drac/drachall4", "east",
        });
    items=({"chains","They look to be weak chains",});
}

