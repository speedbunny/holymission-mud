inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "south coast";
       long_desc = "Here is one of the most quiet place of the island. No noise is coming from the\n" +
                   "swamps or the ocean. All you hear is your heart bumping. You listen a bit to\n" +
                   "make sure that you are still alive.\n";

       dest_dir = ({"players/muzmuz/island/rooms/fp","north",
                    "players/muzmuz/island/rooms/eq","west",
                    "players/muzmuz/island/rooms/gq","east",
                            });
       items =({"swamps","Huge moist swamps",
                  "ocean","The blue ocean",
                       });
       set_light (1);
       }
}
