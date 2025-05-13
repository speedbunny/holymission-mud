
/* prisoner */

inherit "/obj/npc";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_name("zenzi the Human");
        set_alt_name("zenzi");
        set_short(query_name());
        set_long(
        "You see Zenzi the daughter of the drunken mayor.\n"+
        "She is a fat blue eyed girl, with blonde hair and a\n"+
        "red potatoe nose. Little red spots are in her face\n"+
        "because she loves chocolate too much. But now she looks\n"+
        "really sad, because her clumsy arms are shackled to the wall.\n");
        load_chat(20,
        ({
           "Zenzi sniffy sadly.\n",
           "Zenzi says: please free me from my shackles.\n",
           "Zenzi says: please 'open' my shackles.\n",
           "Zenzi outch my shackles hurt so much.\n",
        }));
        set_race("elf");
        set_level(1); 
     }
}

int attack()
{
    this_object()->hold(this_object(),20);
    return 1;
}

void init()
{
    add_action("fcn_open","open");
    ::init();
}

int fcn_open(string arg)
{
    if (arg!="shackles")
        return 0;
    tell_room(environment(),
    "Zenzi says: Thank you so much "+this_player()->query_name()+"\n");
    write("Zenzi kisses you and waves happily.\n");
    say("Zenzi waves happily.\n",this_player());
    this_player()->set_quest("free_zenzi");
    destruct(this_object());
    return 1;
}
 

        

