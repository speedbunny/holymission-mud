inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
     short_desc = "east coast";
      long_desc = "You are walking along the coast. The ocean leads far to the east, you can\n" +
                  "only see water. It is very silent and it seems to be peaceful here.\n";

        dest_dir =({"players/muzmuz/island/rooms/il","north",
                    "players/muzmuz/island/rooms/in","south",
                    "players/muzmuz/island/rooms/hm","west",
                             });
        items =({"ocean","The blue ocean",
                 "water","Clear water",
                     });
        set_light (1);
        }
}
