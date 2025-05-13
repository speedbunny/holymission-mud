inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "dunes";
      long_desc = "You reached the southern end of the dunes. South from here are hills.\n" +
                   "It isn`t as hot as at the inner dunes by far.\n";

        dest_dir =({"players/muzmuz/island/rooms/hf","north",
                    "players/muzmuz/island/rooms/hh","south",
                    "players/muzmuz/island/rooms/gg","west",
                    "players/muzmuz/island/rooms/ig","east",
                       });

        items =({"dunes","Huge dunes, covered with sand",
                 "sand","Hot white sand",
                 "hills","Little hills",
                          });
        set_light (1);
        }
}
