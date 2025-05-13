inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {

      short_desc = "path";
      long_desc = "You are walking along the path. There are hills to the north and to the south.\n" +
                   "Unfortunately you cannot climb them.\n",

         dest_dir = ({"players/muzmuz/island/rooms/ih","west",
                      "players/muzmuz/island/rooms/kh","east",
                               });
          items =({"path","A stony path",
                   "hills","Little hills, but too steep to climb up",
                         });
      set_light (1);
      }
}
