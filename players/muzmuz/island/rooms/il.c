inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {

       short_desc = "east coast";
       long_desc = "You are at the coast. The ocean is silent, it seems to be lifeless.\n" +
                    "To the west you can see the swamps.\n";

          dest_dir =({"players/muzmuz/island/rooms/ik","north",
                      "players/muzmuz/island/rooms/im","south",
                      "players/muzmuz/island/rooms/hl","west",
                             });

           items =({"ocean","The blue ocean",
                    "swamps","Huge moist swamps",
                            });
           set_light (1);
          }
}
