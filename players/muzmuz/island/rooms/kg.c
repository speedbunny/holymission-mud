inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {

      short_desc = "east coast";
       long_desc = "You are at the coast, north from the anchoring place. To the west is\n" +
                   "a little hill. The ocean is very silent and blue.\n";

       dest_dir = ({"players/muzmuz/island/rooms/jf","northwest",
                     "players/muzmuz/island/rooms/jg","west",
                     "players/muzmuz/island/rooms/kh","south",
                               });

         items = ({"ocean","The blue ocean",
                   "coast","The east coast of the island",
                   "anchoring place","A little jetty",
                   "hill","A little hill",
                       });
       set_light (1);
       }
}
