inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
        short_desc = "hill";
         long_desc = "You are standing on the top of a little hill. You can overlook a bit part of \n" +
                     "the island from here. The view reaches deep into the swamps and it seems like\n" +
                     "you can hear the buzz of the mosquitos from there.\n";

         dest_dir =({"players/muzmuz/island/rooms/ho","north",
                     "players/muzmuz/island/rooms/hq","south",
                     "players/muzmuz/island/rooms/gp","west",
                     "players/muzmuz/island/rooms/ip","east",
                            });
         items =({"swamps","Huge moist swamps",
                  "mosquitos","They are too far away to see them",
                  "island","The Island of Death",
                          });
        set_light (1);
        }
}
