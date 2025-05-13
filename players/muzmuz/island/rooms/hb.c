inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
       short_desc = "coast";
        long_desc = "This is the northern part of the coast. To the west there are the dunes.\n" +
                    "It is windy here and so it doesn`t seem to be so hot. You haven`t ever seen \n" +
                    "such a blue ocean before.\n";

           dest_dir = ({"players/muzmuz/island/rooms/ha","north",
                        "players/muzmuz/island/rooms/hc","south",
                        "players/muzmuz/island/rooms/gb","west",
                                   });

           items = ({"ocean","The blue ocean",
                     "dunes","Huge dunes, covered with sand",
                       });
           set_light (1);
           }
}
