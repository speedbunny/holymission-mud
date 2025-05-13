inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {

       short_desc = "hill";
        long_desc = "Among the hills. To the north you see the dunes, to the south there is the\n" +
                    "path which leads through the island. Unfortunately  the southern side of the\n" +
                    "hill is too steep to go down directly.\n";

        dest_dir = ({"players/muzmuz/island/rooms/eg","north",
                     "players/muzmuz/island/rooms/dh","west",
                     "players/muzmuz/island/rooms/fh","east",
                       });

        items = ({"dunes","Huge dunes, coered with sand",
                  "hills","Little hills",
                  "path","A stony path to the south from here",
                    });
        set_light (1);
        }
}
