inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "north coast";
       long_desc = "The north coast. The blue ocean is to the north and to the south you can see\n" +
                   "the dunes. The wind blowing into your face dries up your sweat.\n";
 
        dest_dir =({"players/muzmuz/island/rooms/ea","west",
                    "players/muzmuz/island/rooms/fb","south",
                    "players/muzmuz/island/rooms/ga","east",
                         });

        set_light (1);
         items = ({"ocean","The blue, silent ocean",
                   "dunes","Huge dunes to the south",
                      });
        }
}
