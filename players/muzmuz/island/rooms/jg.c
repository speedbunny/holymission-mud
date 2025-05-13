inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "hill";
      long_desc ="You are standing on the top of a little hill. If you look to the northwest, \n" +
                 "you can have a look into the dunes. They look very dry and it seems to be very\n" +
                 "hot there. South from here is the path leading through the island. Too bad \n" +
                 "that the southern side of the hill is too steep to go down directly. The \n" +
                 "ocean to the east presents itself in the deepest blue you can imagine.\n" +
                 "Southwest you can see the anchoring place.\n";

       dest_dir = ({"players/muzmuz/island/rooms/jf","north",
                    "players/muzmuz/island/rooms/ig","west",
                    "players/muzmuz/island/rooms/kg","east",
                      });

         items = ({"dunes","Huge dunes, covered with sand",
                   "path","A stony path",
                   "hill","A little hill from where you can look deep into the dunes",
                   "island","The island of death...it looks peaceful from here",
                   "ocean","The blue ocean",
                          });
        set_light (1);
        }
}
