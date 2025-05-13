inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "hills";
       long_desc = "You are on the top of a hill. The dunes are to the north. There is a stony\n" +
                   "path to the south. The southern side of the hill is rather steep.\n";

           dest_dir = ({"players/muzmuz/island/rooms/fg","north",
                        "players/muzmuz/island/rooms/eh","west",
                        "players/muzmuz/island/rooms/gh","east",
                             });

          items = ({"dunes","Huge dunes, covered with sand",
                    "hills","Little hills",
                    "path","A stony path",
                            });
          set_light (1);
          }
}
