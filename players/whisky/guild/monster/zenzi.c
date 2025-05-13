
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
           "Zenzi says: outch my shackles hurt so much.\n",
        }));
        set_race("elf");
        set_level(1); 
        set_gender(2);
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
    add_action("fcn_open","unlock");
    ::init();
}

int fcn_open(string arg)
{
   object key;

    if (arg!="shackles" && arg!="shackles with key")
        return 0;
    if (!(key=present("zenzi_key",this_player())))
    {
        write("But you don't have the proper key.\n");
        say(this_player()->query_name()+" tries to open the shackles, "+
           "but fails.\n",this_player());
        return 1;
    }
    tell_room(environment(),
    "Click, your key broke, but the shackles are open !\n");
    destruct(key);
    call_out("thank_pl",2);
    return 1;
}

void thank_pl()
{
    tell_room(environment(),
    "Zenzi says: Thank you so much "+this_player()->query_name()+"\n");
    write("Zenzi kisses you.\n");
    say("Zenzi kisses "+this_player()->query_name()+"\n",this_player());
    this_player()->set_quest("free_zenzi");
    call_out("leave_out",2);
}

void leave_out() 
{
    tell_room(environment(),"Zenzi leaves west.\n");
    destruct(this_object());
    return;
}

int run_away()
{
    return 0;
}

        

