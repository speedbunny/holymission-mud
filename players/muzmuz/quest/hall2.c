inherit "room/room";

void reset (int arg)
{
    if(!arg)
    {

       short_desc = "Hall";
        long_desc = "You are in the northern part of the hall. Stairs lead downwards. \n" +
                    "On the wall you can see a picture.\n";

        items =({"stairs","They lead downwards",
                 "picture","It shows an old man",
                           });

     dest_dir = ({"players/muzmuz/quest/hall","south",
                  "players/muzmuz/quest/cellar","downstairs",
                             });
    hidden_dir =({"/players/muzmuz/quest/cellar","down",
                           });


        set_light (1);
}
}


