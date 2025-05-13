/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Thieves' Fence =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

inherit "/obj/std_shop";

int x;
void reset(int flag)
{
    ::reset(flag);
    short_desc = "The Fence";
    long_desc =
    "This is the Thieves' Fence of Holy Mission.\n"
    + "Here you may buy and sell items obtained by you and your fellow thieves.\n"
    + "A pair of swinging doors leads east to the guild proper.\n"
    + "Commands are:\n"
    + "  'list', 'buy <num>', 'buy <item>', 'sell <item>', \n"
    + "          'sell <all>', 'value <item>'.\n";
    store = "guild/master"->query_dir(1) + "/store";
    keeper = "The fence";
    dest_dir = ({  "guild/master"->query_room(1), "east"  });
    if (!present("torch",query_store()))
    {
        for(x=0;x<5;x++)
        {
            move_object(clone_object("/players/whisky/obj/torch"),
                        query_store());
        }
     }
    if (!present("snare",query_store())) {
        for(x=0;x<3;x++)
        {
            move_object(clone_object("/players/blade/guild/obj/snare"),
                        query_store());
        }
   }


    if (!present("blue scroll",query_store()))
    {
         for(x=0;x<4;x++)
        {
            move_object(clone_object("/players/whisky/obj/recall_scroll"),
                        query_store());
        }
   }
  if (!present("trashcan",this_object()))
     move_object(
          clone_object("players/whisky/shops/trashcan"),this_object());
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

