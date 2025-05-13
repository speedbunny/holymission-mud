inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {
      short_desc = "dunes";
       long_desc = "The eastern edge of the dunes. The coast is not far away and you better\n" +
                   "go there. The west, which leads to the inner dunes, doesn`t look very inviting.\n";

        dest_dir = ({"players/muzmuz/island/rooms/ie","north",
                     "players/muzmuz/island/rooms/ig","south",
                     "players/muzmuz/island/rooms/hf","west",
                     "players/muzmuz/island/rooms/jf","east",
                                    });
 
           items = ({"dunes","Huge dunes, covered with sand",
                     "sand","Hot white sand",
                     "coast","Too far away to see it",
                             });
          set_light (1);
          }
}
