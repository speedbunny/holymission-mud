inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
          short_desc = "path";
           long_desc = "On the stony path. You can only go east or west. You wonder if you will\n" +
                       "ever meet someone here.\n";

          dest_dir = ({"players/muzmuz/island/rooms/ei","west",
                       "players/muzmuz/island/rooms/gi","east",
                          });

            items = ({"path","A stony path",
                      "hills","Little hills, but too steep to climb",
                                   });
         set_light (1);
         }
}
