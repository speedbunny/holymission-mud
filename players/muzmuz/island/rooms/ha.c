inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
          short_desc = "northeastern corner";
          long_desc = "You are at the northeastern corner of this part of the island. This place is \n" +
                       "exposed and rather windy. To the north and east you only see the ocean.\n" +
                       "Southwest from here are the dunes.\n";

             dest_dir = ({"players/muzmuz/island/rooms/ga","west",
                          "players/muzmuz/island/rooms/hb","south",
                                    });

           items = ({"dunes","Huge dunes, covered with sand",
                     "ocean","The blue, lifeless ocean",
                              });
           set_light (1);
           }
}
