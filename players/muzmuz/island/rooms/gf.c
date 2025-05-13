inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "dunes";
       long_desc = "You are in the southeastern part of the dunes. It is very hot here.\n" +
                   "You can feel that in the west it is even hotter.\n";

        dest_dir = ({"players/muzmuz/island/rooms/ge","north",
                     "players/muzmuz/island/rooms/gg","south",
                     "players/muzmuz/island/rooms/ff","west",
                     "players/muzmuz/island/rooms/hf","east",
                             });

          items = ({"dunes","Huge dunes, covered with sand",
                    "sand","Hot white sand",
                          });
          set_light (1);
          }
}
