inherit "room/room" ;

void reset(int arg) 
{
   if(!arg) 
   {

     short_desc = "West coast";
 
      long_desc ="At the west coast of the island. High above you you can see some clouds\n" +
                  "drifting around. But the don`t seem to cause rain, they are too tiny. It is\n" +
                  "very peaceful here, not even a ghost of death.\n";
           
            items = ({"sand","Hot white sand",
                      "ocean","The blue ocean is quiet"});

           dest_dir = ({"players/muzmuz/island/rooms/ae","north",
                       "players/muzmuz/island/rooms/ag","south",
                       "players/muzmuz/island/rooms/bf","east",

                     });

         set_light (1);
     }
  }
