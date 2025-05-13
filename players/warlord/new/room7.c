

inherit "room/room";
object ob,oc,od,oe,of;

reset(arg) {
    if (arg) return;
    if(!ob){ob=clone_object("players/warlord/monsters/fairy");move_object(ob,this_object());}
    if(!oc){oc=clone_object("players/warlord/monsters/fairy");move_object(oc,this_object());}
    if(!od){od=clone_object("players/warlord/monsters/fairy");move_object(od,this_object());}
if(!oe){oe=clone_object("players/warlord/monsters/fairy");move_object(oe,this_object());}
if(!of){of=clone_object("players/warlord/monsters/fairy");move_object(of,this_object());}

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This is the end of the hallway... You thought that you would\n"
        + "never reach it...\n";
    dest_dir = 
        ({
        "players/warlord/new/room6","south",
        });
}

