inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
        short_desc = "south coast";
        long_desc = "You are at the eastern part of the south coast. The swamps are to the \n" +
                      "northwest. The little hill near can be climbed. Once you reached its top, you \n" +
                      "can enjoy the view.\n";
 
        dest_dir =({"players/muzmuz/island/rooms/gp","north",
                    "players/muzmuz/island/rooms/fq","west",
                    "players/muzmuz/island/rooms/hq","east",
                            });
        items = ({"swamps","Hot moist swamps",
                  "hill","A little hill to the northeast",
                  "ocean","The blue ocean",
                         });
        set_light (1);
        }
}
