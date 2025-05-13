inherit "room/room";

void reset (int arg) 
{
  if(!arg) 
  {

      short_desc = "northern bay";
       long_desc = "This is the northern side of the bay. From here you can see the anchoring\n" +
                   "place and to the west and to the north are dunes.\n";

       items = ({"anchoring place","A little anchoring place where boats land",
                 "dunes","Huge dunes"});
        dest_dir = ({"players/muzmuz/island/rooms/bg","north",
                     "players/muzmuz/island/rooms/ah","west",
                     "players/muzmuz/island/rooms/ch","east",

                  });

      set_light (1);
      }
}
