inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
       short_desc = "path";
        long_desc = "You are on the stony path leading through the island. The path is leading \n" +
                    "further to the south and to the east. If you go north, you enter the dunes.\n" +
                    "To the west there is a little hill.\n";

        dest_dir =({"players/muzmuz/island/rooms/ig","north",
                    "players/muzmuz/island/rooms/ii","south",
                    "players/muzmuz/island/rooms/jh","east",
                         });
         items = ({"dunes","Huge dunes, covered with sand",
                   "hill","A little hill, but too steep to climb up",
                           });
         set_light (1);
         }
}
