inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {

        short_desc ="swamps";
         long_desc ="You are at the northern end of the swamps. Steep hills are to the north.\n" +
                    "It is warm and moist here. \n";

        dest_dir =({"players/muzmuz/island/rooms/dl","west",
                    "players/muzmuz/island/rooms/fl","east",
                    "players/muzmuz/island/rooms/em","south",
                          });

         items = ({"hills","Steep hills to the north",
                   "swamps","Huge swamps to the south",
                          });
        set_light (1);
       }
}
