inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "east coast";
       long_desc = "You are walking along the coast. A gentle breeze blows into your face.\n" +
                   "West from here you can see the dunes. They seem to be very dry and hot. The\n" +
                   "ocean is very silent. South from here is a little hill.\n";

         dest_dir = ({"players/muzmuz/island/rooms/je","north",
                      "players/muzmuz/island/rooms/jg","south",
                      "players/muzmuz/island/rooms/kg","southeast",
                      "players/muzmuz/island/rooms/if","west",
                               });

           items = ({"ocean","The blue ocean",
                     "dunes","Huge dunes, covered with sand",
                     "hill","A little hill",
                                 });
         set_light (1);
         }
}
