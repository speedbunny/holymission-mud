inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "anchoring place";
       long_desc ="This is the eastern anchoring place with a jetty. Boats bring people here\n" +
                  "so that they can investigate this place. The path leads deeper into the \n" +
                  "island.\n";

       dest_dir = ({"players/muzmuz/island/rooms/kg","north",
                    "players/muzmuz/island/rooms/ki","south",
                    "players/muzmuz/island/rooms/jh","west",
                    "players/muzmuz/island/rooms/jetty","jetty",
                            });
        items =({"ocean","The blue ocean",
                 "path","A stony path",
                    });
        set_light (1);
        }
}
