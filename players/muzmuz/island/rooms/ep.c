inherit "room/room";

void reset (int arg) 
{
  if (!arg)
  {

      short_desc = "swamps";
      long_desc = "This is the southwestern part of the swamps. The south coast is near and it\n" +
                   "is not that hot here. \n";

         dest_dir =({"players/muzmuz/island/rooms/eo","north",
                     "players/muzmuz/island/rooms/eq","south",
                     "players/muzmuz/island/rooms/dp","west",
                     "players/muzmuz/island/rooms/fp","east",
                             });
         items = ({"swamps","Huge moist swamps",
                             });
      set_light (1);
      }
}
