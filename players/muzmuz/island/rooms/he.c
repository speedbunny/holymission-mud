inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
       short_desc = "dunes";
       long_desc = "In the eastern part of the dunes. It is uncomfortably warm and dry here.\n" +
                    "The coast is not too far away in the eastern direction. The west leads deeper\n" +
                    "into the dunes, where it is very hot and dry.\n";

        dest_dir =({"players/muzmuz/island/rooms/hd","north",
                    "players/muzmuz/island/rooms/hf","south",
                    "players/muzmuz/island/rooms/ge","west",
                    "players/muzmuz/island/rooms/ie","east",
                             });

         items = ({"dunes","Huge dunes, covered with sand",
                   "sand","Hot white sand",
                   "coast","Too far away to see it",
                          });
          set_light (1);
          }
}
