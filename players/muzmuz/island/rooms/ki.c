inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
       short_desc = "east coast";
       long_desc = "This is the coast, south from the anchoring place. The ocean looks \n" +
                    "wonderful from here. There is a little hill to the west.\n";

        dest_dir =({"players/muzmuz/island/rooms/kh","north",
                    "players/muzmuz/island/rooms/kj","south",
                    "players/muzmuz/island/rooms/ji","west",
                            });

         items = ({"ocean","The blue ocean",
                   "hill","A little hill",
                   "anchoring place","A little anchoring place with a jetty",
                          });
         set_light (1);
         }
}
