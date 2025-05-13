inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {
      short_desc = "dune";
       long_desc = "You are standing inside the dunes. You see that it is often windy here.\n" +
                   "The air is rather dry.\n";

      items = ({"dunes","Huge dunes, covered with sand",
                "sand","Hot white sand",
                       });
             dest_dir = ({"players/muzmuz/island/rooms/cd","north",
                          "players/muzmuz/island/rooms/be","west",
                          "players/muzmuz/island/rooms/cf","south",
                          "players/muzmuz/island/rooms/de","east",
                         });
      set_light (1);
     }
}
