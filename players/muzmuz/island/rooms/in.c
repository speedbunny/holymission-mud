inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
       short_desc = "east coast";
        long_desc = "This is in the southern part of the coast. The ocean is very silent and\n" +
                    "peaceful. The swamps behind you don`t look very nice. It is very hot and \n" +
                    "moist there. Think about it twice if you want to enter them.\n" ;

       dest_dir =({"players/muzmuz/island/rooms/im","north",
                   "players/muzmuz/island/rooms/io","south",
                   "players/muzmuz/island/rooms/hn","west",
                                });
         items =({"ocean","The blue ocean",
                  "swamps","Huge moist swamps",
                          });
         set_light (1);
         }
}
