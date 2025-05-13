inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "hills";
       long_desc = "You are between hills. Hot air from the dunes blows into your face.\n" +
                   "The stony path south looks tiny from here. To the west and to the east are\n" +
                   "more hills.\n";

          dest_dir = ({"players/muzmuz/island/rooms/gg","north",
                       "players/muzmuz/island/rooms/fh","west",
                       "players/muzmuz/island/rooms/hh","east",
                            });

          items = ({"dunes","Huge dunes, covered with sand",
                    "hills","Many little hills",
                    "path","A stony path",
                         });
         set_light (1);
         }
}
