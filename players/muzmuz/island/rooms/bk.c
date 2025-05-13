inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

    short_desc = "south bay";
     long_desc = "You are south of the bay. From here you can see the anchoring place, but it\n" +
                 "is far away. To the south there is boggy land.\n";

      items = ({"anchoring place","A little anchoring place where boats can land",
                "boggy land","Many hills to the south"});
     dest_dir = ({"players/muzmuz/island/rooms/ak","west",
                  "players/muzmuz/island/rooms/ck","east",
                  "players/muzmuz/island/rooms/bl","south",
                    });
     set_light (1); 
     }
}

