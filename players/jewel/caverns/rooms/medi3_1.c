inherit "room/room";

string chats;

reset(arg) 
{
    object cmonster, weapon;
    int n,i,class,value,weight;
    string w_name, alt_name;

    if (!arg)
    {
       set_light(0);
       short_desc = "short for medi3_1";
       no_castle_flag = 0;
       long_desc = "blah blah blah. medi3_1.c\n";
       dest_dir = 
           ({"players/jewel/room/medi3_2", "south",
             "players/jewel/room/medi2_1", "east", 
             "players/jewel/room/medi3", "north",
             "players/jewel/room/medi4_1","west"
           });
    }
    i = 0;
    if (!present("Crystal Monster")) 
    {
        while(i<2) 
        {
            i += 1;
            cmonster = clone_object("obj/monster");
            call_other(cmonster, "set_name", "Crystal Monster");
            call_other(cmonster, "set_alias", "dirty crap");
            call_other(cmonster, "set_race", "monster");
            call_other(cmonster, "set_level", random(2) + 1);
            call_other(cmonster, "set_hp", 30);
            call_other(cmonster, "set_ep", 1014);
            call_other(cmonster, "set_al", -60);
            call_other(cmonster, "set_short", "A crystal monster");
            call_other(cmonster, "set_long", "A blah blah blah crystal monster.\n");
            call_other(cmonster, "set_ac", 0);
            call_other(cmonster, "set_aggressive", 0);
            call_other(cmonster, "load_a_chat", 50, get_chats());
            n = random(3);
            weapon = clone_object("obj/weapon");
            if (n == 0) {
                w_name = "knife";
                class = 5;
                value = 8;
                weight = 1;
            }
            if (n == 1) {
                w_name = "curved knife";
                class = 7;
                value = 15;
                weight = 1;
                alt_name = "knife";
            }
            if (n == 2) {
                w_name = "hand axe";
                class = 9;
                value = 25;
                weight = 2;
                alt_name = "axe";
            }
            call_other(weapon, "set_name", w_name);
            call_other(weapon, "set_class", class);
            call_other(weapon, "set_value", value);
            call_other(weapon, "set_weight", weight);
            call_other(weapon, "set_alt_name", alt_name);
            transfer(weapon, cmonster);
            command("wield " + w_name, cmonster);
            move_object(cmonster, this_object());
        }
    }

}

get_chats() {
    if (!chats) {
        chats = allocate(3);
        chats[0] = "Crystal monster says: DIE!\n";
        chats[1] = "Crystal monster glows in the pretty light.\n";
        chats[2] = "Crystal monster says: I'm too sharp for you\n";
    }
    return chats;
}

query_light() {
    return 1;
}



