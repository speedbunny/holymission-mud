inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {

      short_desc = "path";
       long_desc = "You are on the path leading through the island. The path is leading further\n" +
                   "to the west and to the north. \n";

         dest_dir = ({"players/muzmuz/island/rooms/hi","west",
                      "players/muzmuz/island/rooms/ih","north",
                                   });
        items = ({"path","A stony path",
                  "hills","Little hills, but too steep to climb up"
                            });
         set_light (1);
         }
}
