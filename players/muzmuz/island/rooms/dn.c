inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

     short_desc = "swamps";
      long_desc = "You are in the swamps. The coast is to the west. It is hot and damp.\n" +
                  "Annoying mosquitos buzz around you.\n";

    items = ({"coast","The west coast",
              "mosquitos","The seem to be anywhere"});
       dest_dir = ({"players/muzmuz/island/rooms/dm","north",
                    "players/muzmuz/island/rooms/do","south",
                    "players/muzmuz/island/rooms/cn","west",
                    "players/muzmuz/island/rooms/en","east",
                       });
     set_light (1); 
     }
}
