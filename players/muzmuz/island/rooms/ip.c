inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "east coast";
       long_desc = "The is the southern corner of the coast. A hill is to the west. The \n" +
                   "seems to be never ending and it is very silent.\n";

        dest_dir =({"players/muzmuz/island/rooms/io","north",
                    "players/muzmuz/island/rooms/hq","southwest",
                    "players/muzmuz/island/rooms/hp","west",
                       });
          items = ({"ocean","The blue ocean",
                    "hill","A little hill",
                          });
        set_light (1);
        }
}
