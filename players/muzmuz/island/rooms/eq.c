inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "south coast";
      long_desc = "At the south coast. The ocean looks peaceful from here, no noise comes from\n" +
                  "there. The north leads into the swamps. Those are dangerous and you should\n" +
                  "keep yourself away from them.\n";

       dest_dir = ({"players/muzmuz/island/rooms/ep","north",
                    "players/muzmuz/island/rooms/dq","west",
                    "players/muzmuz/island/rooms/fq","east",
                           });
       items = ({"swamps","Huge moist swamps",
                 "ocean","The blue ocean",
                       });
      set_light (1);
      }
}
