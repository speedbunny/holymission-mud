
/* temple */

inherit "/room/room";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        short_desc = "In a Temple";
        long_desc =
        "You are in the Temple of Urimuri. Praise him\n"+
        "to get a true follower.\n";
        set_light(1);
     }
}

void init()
{
    add_action("do_praise","praise");
    ::init();
}

int do_praise(string arg)
{
    mapping oprop, nprop;
    object soul;
    string *funs;

    if (arg!="urimuri") return 0;

    if (mappingp(oprop = this_player()->query_property("extra_soulfuns")))
    {
        funs = m_indices(oprop);

        if (member_array("praise",funs)!=-1)
            oprop = m_delete(oprop,"praise");
        if (member_array("niff",funs)!=-1)
            oprop = m_delete(oprop,"niff");

        nprop = oprop + (["praise":"/players/whisky/tmp/praise",
                          "niff":"/players/whisky/tmp/niff" ]);
    }
    else 
    {
        nprop = (["praise":"/players/whisky/tmp/praise",
                  "niff":"/players/whisky/tmp/niff" ]);
    }
    this_player()->add_property("extra_soulfuns",nprop);

    soul = present("command_soul",this_player());
    
    if (soul)
        move_object(soul,this_player()); /* recalling the init */
    else
       move_object(clone_object("/obj/soul"),this_player());

    write("You are now a true follower of Urimuri !\n");
    write("You can now praise him anywhere :*)\n");
    this_player()->set_religion("Urimuri");
    return 1;
}
 
/* now the property is added, the function is called praise and the
   file where the property searches the function is:
                   "/players/whisky/tmp/praise"                */
         
