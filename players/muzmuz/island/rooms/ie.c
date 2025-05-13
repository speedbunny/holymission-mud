inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {

     short_desc = "dunes";
      long_desc = "This is the eastern edge of the dunes. The coast is near, but still too\n" +
                  "far away to see it yet. The west is leading deeper into the dunes.\n";

       dest_dir = ({"players/muzmuz/island/rooms/id","north",
                    "players/muzmuz/island/rooms/if","south",
                    "players/muzmuz/island/rooms/he","west",
                    "players/muzmuz/island/rooms/je","east",
                             });

          items = ({"dunes","Huge dunes, covered with sand",
                    "sand","Hot white sand",
                    "coast","Too far away to see it",
                           });
         set_light (1);
         }
}
