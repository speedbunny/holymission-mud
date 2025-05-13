inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
   short_desc = "north coast";
    long_desc = "You are standing at the north coast. All you can see is the \n" +
                "ocean to the north and the dunes to the south.\n";

    dest_dir = ({"players/muzmuz/island/rooms/fa","west",
                 "players/muzmuz/island/rooms/ha","east",
                 "players/muzmuz/island/rooms/gb","south",
                          });
     items =({"ocean","The blue ocean.",
              "dunes","Huge dunes, covered with sand",
                    });
     set_light (1);
     }
}
