inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
 {
       short_desc = "east coast";
        long_desc = "You have reached the western part of the little bay. Hills are to the north\n" +
                    "and to the west. They and the silent ocean make this place special.\n";

         dest_dir =({"players/muzmuz/island/rooms/jj","northeast",
                     "players/muzmuz/island/rooms/il","south",
                            });

        items =({"bay","A little romantic bay",
                 "ocean","The blue ocean",
                 "hills","Steep hills",
                          });
         set_light (1);
        }
}
