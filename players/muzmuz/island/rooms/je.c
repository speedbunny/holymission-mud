inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
       short_desc = "east coast";
       long_desc = "You are standing at the coast of the island. It is very silent here,\n" +
                    "only the wind blows a bit. The dunes are to the west, the ocean to the\n" +
                    "east. You wonder if there has ever life existed here.\n";

         dest_dir = ({"players/muzmuz/island/rooms/id","northwest",
                      "players/muzmuz/island/rooms/jf","south",
                      "players/muzmuz/island/rooms/ie","west",
                  
                                });

            items = ({"ocean","The blue ocean",
                      "dunes","Huge dunes, covered with sand",
                             });
         set_light (1);
         }
}
