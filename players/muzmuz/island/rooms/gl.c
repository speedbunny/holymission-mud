inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {
         short_desc = "swamps";
          long_desc = "This is the northern end of the swamps. It is less warm and moist here than\n" +
                      "deeper inside, but you still feel uncomfortable.\n";

          dest_dir =({"players/muzmuz/island/rooms/fl","west",
                      "players/muzmuz/island/rooms/hl","east",
                      "players/muzmuz/island/rooms/gm","south",
                              });

          items = ({"hills","Steep hills to the north",
                       "swamps","Huge moist swamps",
                                 });
          set_light (1);
          }
}
