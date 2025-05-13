inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {
    short_desc = "east coast";
     long_desc = "You are walking along the northern part of the coast. The ocean to the\n" +
                 "east seems lifeless. To the west there are the dunes.\n";

     dest_dir = ({"players/muzmuz/island/rooms/hc","northwest",
                  "players/muzmuz/island/rooms/ie","south",
                  "players/muzmuz/island/rooms/hd","west",
                  "players/muzmuz/island/rooms/je","southeast",
                       });

        items = ({"ocean","The blue ocean",
                  "dunes","Huge dunes, covered with sand",
                            });
        set_light (1);
       }
}
