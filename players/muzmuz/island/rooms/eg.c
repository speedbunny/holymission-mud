inherit "room/room";

void reset (int arg) 
{
   if (!arg) 
   {

     short_desc = "dunes";
      long_desc = "The southern edge of the dunes. Here it is less hot than inside them. There\n" +
                  "are some hills to the south.\n";

     dest_dir = ({"players/muzmuz/island/rooms/ef","north",
                  "players/muzmuz/island/rooms/dg","west",
                  "players/muzmuz/island/rooms/fg","east",
                  "players/muzmuz/island/rooms/eh","south",
                    });

       items = ({"dunes","Huge dunes, covered with sand",
                 "sand","Hot white sand",
                   });
     set_light (1);
     }
}
