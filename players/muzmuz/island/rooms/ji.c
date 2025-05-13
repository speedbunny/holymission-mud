inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
       short_desc = "hill";
       long_desc = "You are on the top of a hill. The path is near, but you cannot climb down \n" +
                    "from here. In the east you see the coast with the anchoring place and the\n" +
                    "the blue ocean.\n";

         dest_dir =({"players/muzmuz/island/rooms/jj","south",
                     "players/muzmuz/island/rooms/ki","east",
                                    });

         items = ({"ocean","The blue ocean",
                   "coast","The east coast",
                   "anchoring place","The anchoring place with a jetty",
                   "path","A stony path",
                            });
         set_light (1);
         }
}
