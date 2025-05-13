

inherit "room/room";
object oa,ob,oc,od,oe;

reset(arg) {
    if (arg) return;
    if(!oa){oa=clone_object("players/warlord/monsters/fairy2");move_object(oa,this_object());}
    if(!ob){ob=clone_object("players/warlord/monsters/fairy2");move_object(ob,this_object());}
    if(!oc){oc=clone_object("players/warlord/monsters/fairy2");move_object(oc,this_object());}
    if(!od){od=clone_object("players/warlord/monsters/fairy2");move_object(od,this_object());}
    if(!oe){oe=clone_object("players/warlord/monsters/fairy2");move_object(oe,this_object());}

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "There are some small flying creatures here... You think they are \n"
        + "fairys, but they are UGLY!\n";
    dest_dir = 
        ({
        "players/warlord/new/room1.c","south",
        });
}



