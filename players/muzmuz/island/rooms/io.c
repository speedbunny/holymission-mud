inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "east coast";
       long_desc = "You are at the southern part of the coast. The wind blowing into your \n" +
                   "face cools you a bit.\n";
     
         dest_dir =({"players/muzmuz/island/rooms/in","north",
                     "players/muzmuz/island/rooms/ip","south",
                     "players/muzmuz/island/rooms/ho","west",
                                   });
            items =({"ocean","The blue ocean",
                     "swamps","Huge moist swamps",
                          });
         set_light (1);
         }
}
