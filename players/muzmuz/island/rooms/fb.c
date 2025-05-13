inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "dunes";
       long_desc = "The north side of the dunes. You are near the north coast of the island.\n" +
                   "To the south you only see dunes. It is getting hot here and you rather look\n" +
                   "for a more comfortable place.\n";

       dest_dir = ({"players/muzmuz/island/rooms/fa","north",
                    "players/muzmuz/island/rooms/fc","south",
                    "players/muzmuz/island/rooms/eb","west",
                    "players/muzmuz/island/rooms/gb","east",
                        });
       items = ({"dunes","Huge dunes, covered with sand",
                 "coast","Too far away to see it yet",
                 "sand","Hot white sand",
                      });
       set_light (1);
       }
}
