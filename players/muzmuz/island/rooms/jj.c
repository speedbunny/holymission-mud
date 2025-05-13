inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "coast";
       long_desc = "You are on the northern side of a little bay. The hills to the north and to\n" +
                   "the west let this place seem romantic.\n";

         dest_dir =({"players/muzmuz/island/rooms/ji","north",
                     "players/muzmuz/island/rooms/kj","east",
                     "players/muzmuz/island/rooms/ik","southwest",
                                });

            items = ({"hills","Little hills to the north and west",
                      "ocean","The blue ocean",
                      "bay","A romantic little bay",
                               });
         set_light (1);
         }
}
