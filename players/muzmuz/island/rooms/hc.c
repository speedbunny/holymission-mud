inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
      short_desc = "east coast";
      long_desc = "You are standing on the northern part of the coast. To the west there are\n" +
                   "the dunes, to the east the ocean.\n";

        dest_dir =({"players/muzmuz/island/rooms/hb","north",
                    "players/muzmuz/island/rooms/hd","south",
                    "players/muzmuz/island/rooms/gc","west",
                    "players/muzmuz/island/rooms/id","southeast",
                              });

          items = ({"ocean","The blue ocean",
                    "dunes","Huge dunes, covered with sand",
                             });
         set_light (1);
         }
}
