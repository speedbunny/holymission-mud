inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
       short_desc = "swamps";
       long_desc = "This is the southeastern corner of the swamps. To the east there is a little\n" +
                    "hill, you can climb up if you want. The view from there might be nice.\n";

       dest_dir =({"players/muzmuz/island/rooms/go","north",
                   "players/muzmuz/island/rooms/gq","south",
                   "players/muzmuz/island/rooms/fp","west",
                   "players/muzmuz/island/rooms/hp","east",
                             });
       items = ({"swamps","Huge moist swamps",
                 "hill","A little hill to the east",
                       });
       set_light (1);
       }
}
