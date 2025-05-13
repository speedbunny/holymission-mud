inherit "room/room";

void reset (int arg)
{
    if(!arg)
    {

     short_desc = "Bedroom";
      long_desc = "You have entered the bedroom. The beds are made. The room is well lit and\n" +
                  "you can see some birds flying outside.\n";

          items = ({"birds","Little sparrows flying around",
                    "bed","You are sure no one has touched it today yet",
                           });

          dest_dir =({"players/bobo/quest/uphall","east",
                                });

           set_light (1);

}
}

