inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "south coast";
       long_desc = "This is the eastern corner of the south coast. This place is exposed and so a\n" +
                   "stiff breeze is blowing into your face. The hill north from you can easily be\n" +
                   "climbed. The swamps are to the northwest.\n";

       dest_dir =({"players/muzmuz/island/rooms/hp","north",
                   "players/muzmuz/island/rooms/gq","west",
                   "players/muzmuz/island/rooms/ip","northeast",
                      });
       items = ({"hill","A little hill",
                 "swamps","Huge moist swamps",
                 "ocean","The blue ocean", 
                          });
        set_light (1);
        }
}
