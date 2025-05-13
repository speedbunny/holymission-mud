inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {

        short_desc = "path";
         long_desc = "You are walking along the path leading through the Island of Death.\n" +
                     "It leads further in east-western direction. The hills to the north and south\n" +
                     "are too steep to climb up.\n";

              dest_dir =({"players/muzmuz/island/rooms/di","west",
                          "players/muzmuz/island/rooms/fi","east",
                                    });

             items = ({"path","A stony path",
                       "hills","Little hills, but too steep to climb up",
                             });
       set_light (1);
      }
}
