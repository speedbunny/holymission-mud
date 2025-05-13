inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
       short_desc = "dunes";
        long_desc = "The southern end of the dunes. Further to the south are little hills. The\n" +
                    "sand is cool enough that your feet don`t get burned.\n";

         dest_dir = ({"players/muzmuz/island/rooms/gf","north",
                      "players/muzmuz/island/rooms/gh","south",
                      "players/muzmuz/island/rooms/fg","west",
                      "players/muzmuz/island/rooms/hg","east",
                             });

          items =({"dunes","Huge dunes, covered with sand",
                   "sand","Hot white sand",
                   "hills","Little hills",
                             });
          set_light (1);
          }
}
