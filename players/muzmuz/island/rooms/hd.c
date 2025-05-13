inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "dunes";
       long_desc = "The east part of the dunes. Are at the edge of them and you can feel that the\n" +
                   "coast is near.\n";

         dest_dir = ({"players/muzmuz/island/rooms/hc","north",
                      "players/muzmuz/island/rooms/he","south",
                      "players/muzmuz/island/rooms/gd","west",
                      "players/muzmuz/island/rooms/id","east",
                         });

        items = ({"dunes","Huge dunes, covered with sand",
                  "sand","Hot white sand",
                  "coast","Too far away to see it",
                            });
        set_light (1);
        }
}
