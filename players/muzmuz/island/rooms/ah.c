inherit "room/room";

void reset (int arg) 
{
  if(!arg) 
  {

              short_desc = "West coast";
               long_desc = "You are at the edge of the bay. You can see the ocean to the west. This part\n" +
                           "of the island is rather peaceful and you think about resting here for awhile\n" +
                           "to gain some power. You are sure that you need lots of power on this island.\n"; 

         items = ({"ocean","A blue ocean without life",
                   "sand","The sand is a little wet"});

                dest_dir = ({"players/muzmuz/island/rooms/ag","north",
                             "players/muzmuz/island/rooms/bh","east",
                       });

          set_light (1);

     }
}
